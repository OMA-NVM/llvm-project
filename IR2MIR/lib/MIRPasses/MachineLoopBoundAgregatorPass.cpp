#include "MIRPasses/MachineLoopBoundAgregatorPass.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/Analysis/ScalarEvolutionExpressions.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

#define DEBUG_TYPE "machine-loop-bound-aggregator"

namespace llvm {

char MachineLoopBoundAgregatorPass::ID = 0;

MachineLoopBoundAgregatorPass::MachineLoopBoundAgregatorPass(TimingAnalysisResults &TAR)
    : MachineFunctionPass(ID), TAR(TAR) {}

void MachineLoopBoundAgregatorPass::getAnalysisUsage(AnalysisUsage &AU) const {
  MachineFunctionPass::getAnalysisUsage(AU);
  AU.setPreservesAll();
  AU.addRequired<MachineLoopInfoWrapperPass>();
  AU.addRequired<LoopInfoWrapperPass>();
  AU.addRequired<ScalarEvolutionWrapperPass>();
}

bool MachineLoopBoundAgregatorPass::runOnMachineFunction(MachineFunction &F) {
  MachineLoopInfo &MLI = getAnalysis<MachineLoopInfoWrapperPass>().getLI();
  LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
  ScalarEvolution &SE = getAnalysis<ScalarEvolutionWrapperPass>().getSE();

  std::unordered_map<const MachineBasicBlock *, unsigned int> LoopBounds;

  // Iterate over all loops in preorder
  for (auto *ML : MLI.getLoopsInPreorder()) {
      MachineBasicBlock *Header = ML->getHeader();
      const BasicBlock *BB = Header->getBasicBlock();
      if (!BB)
        continue;

      Loop *L = LI.getLoopFor(BB);
      if (!L)
        continue;

      // Check if the IR loop header matches the Machine loop header's BB
      // This ensures we are looking at the same loop structure
      if (L->getHeader() != BB)
        continue;

      unsigned TripCount = SE.getSmallConstantTripCount(L);
      // getSmallConstantTripCount returns 0 if unknown or not constant.
      // It also returns the exact trip count, not the bound.
      // But for timing analysis, exact trip count is often what we want if it's constant.
      // If it's not constant, we might want max backedge taken count.

      if (TripCount == 0) {
          // Try to get max backedge taken count
          const SCEV *MaxBTC = SE.getConstantMaxBackedgeTakenCount(L);
          if (auto *C = dyn_cast<SCEVConstant>(MaxBTC)) {
              TripCount = C->getAPInt().getZExtValue() + 1; // Trip count is BTC + 1
          }
      }

      if (TripCount > 0) {
        LoopBounds[Header] = TripCount;
        LLVM_DEBUG(dbgs() << "Loop bound for MBB " << Header->getNumber()
                          << " (IR " << BB->getName() << "): " << TripCount << "\n");
      }
  }

  // Merge with existing bounds if any (though this pass runs once per function, TAR is global/shared?)
  // TAR seems to be passed around. If we run this pass on multiple functions, we should accumulate.
  // But TAR.LoopBoundMap is a map.
  // We should probably fetch existing map, update it, and set it back.

  auto ExistingBounds = TAR.getLoopBoundMap();
  ExistingBounds.insert(LoopBounds.begin(), LoopBounds.end());
  TAR.setLoopBoundMap(ExistingBounds);

  return false;
}

MachineFunctionPass *createMachineLoopBoundAgregatorPass(TimingAnalysisResults &TAR) {
  return new MachineLoopBoundAgregatorPass(TAR);
}

} // namespace llvm
