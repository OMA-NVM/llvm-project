#include "MIRPasses/CallSplitterPass.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {

char CallSplitterPass::ID = 0;

/**
 * @brief Construct a new Asm Dump And Check Pass:: Asm Dump And Check Pass
 * object
 *
 * @param TM
 */
CallSplitterPass::CallSplitterPass(TargetMachine &TM)
    : MachineFunctionPass(ID), TM(TM) {}

/**
 * @brief Checks if unknown Instructions were found.
 *        Always returns false.
 *
 * @return false
 */
bool CallSplitterPass::doFinalization(Module &M) { return false; }

/**
 * @brief Iterates over MachineFunction
 *        and dumps its content into a File.
 *
 * @param F
 * @return true
 * @return false
 */
bool CallSplitterPass::runOnMachineFunction(MachineFunction &F) {
  if (DebugPrints) {
    outs() << "MachineFunction: " << F.getName() << "\n";
  }

  // Get the MachineLoopInfo analysisresults
  auto &MLWP = getAnalysis<MachineLoopInfoWrapperPass>();
  auto &MLI = MLWP.getLI();

  // Get the LoopInfo analysis results
  auto &LWP = getAnalysis<LoopInfoWrapperPass>();
  auto &LI = LWP.getLoopInfo();

  // Get the ScalarEvolution analysis results
  auto &SEWP = getAnalysis<ScalarEvolutionWrapperPass>();
  auto &SE = SEWP.getSE();

  if (DebugPrints) {
    outs() << "MachineLoopInfo: \n";
    MLI.print(outs());
  }

  if (DebugPrints) {
    outs() << "LoopInfo: \n";
    LI.print(outs());
  }

  if (DebugPrints & !LI.empty()) {
    outs() << "ScalarEvolution: \n";
    SE.print(outs());
  }

  for (auto &MBB : F) {
    for (auto &MI : MBB) {
    }
  }
  return false;
}


MachineFunctionPass *llvm::createCallSplitterPass(TargetMachine &TM) {
  return new CallSplitterPass(TM);
}
} // namespace llvm
