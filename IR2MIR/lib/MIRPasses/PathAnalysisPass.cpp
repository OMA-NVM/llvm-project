#include "MIRPasses/PathAnalysisPass.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

char PathAnalysisPass::ID = 0;

/**
 * @brief Construct a new Asm Dump And Check Pass:: Asm Dump And Check Pass
 * object
 *
 * @param TM
 */
PathAnalysisPass::PathAnalysisPass(TargetMachine &TM)
    : MachineFunctionPass(ID), TM(TM) {}

/**
 * @brief Checks if unknown Instructions were found.
 *        Always returns false.
 *
 * @return false
 */
bool PathAnalysisPass::doFinalization(Module &M) { return false; }

/**
 * @brief Iterates over MachineFunction
 *        and dumps its content into a File.
 *
 * @param F
 * @return true
 * @return false
 */
bool PathAnalysisPass::runOnMachineFunction(MachineFunction &F) {
  if (DebugPrints) {
    outs() << "MachineFunction: " << F.getName() << "\n";
  }

  // Get CallGraph analysis results
  if (CG == nullptr) {
    auto &CGWP = getAnalysis<CallGraphWrapperPass>();
    CG = &CGWP.getCallGraph();
    CG->print(outs());
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

} // namespace TimingAnalysisPass

MachineFunctionPass *llvm::createPathAnalysisPass(TargetMachine &TM) {
  return new PathAnalysisPass(TM);
}
