#include "MIRPasses/PathAnalysisPass.h"
#include "TimingAnalysisResults.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/ScalarEvolutionAliasAnalysis.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include <gurobi_c++.h>

namespace llvm {

char PathAnalysisPass::ID = 0;

/**
 * @brief Construct a new Asm Dump And Check Pass:: Asm Dump And Check Pass
 * object
 *
 * @param TM
 */
PathAnalysisPass::PathAnalysisPass(TimingAnalysisResults &TAR)
    : MachineFunctionPass(ID), TAR(TAR) {}

/**
 * @brief Checks if unknown Instructions were found.
 *        Always returns false.
 *
 * @return false
 */
bool PathAnalysisPass::doFinalization(Module &M) { return false; }

Function *PathAnalysisPass::getStartingFunction(CallGraph &CG) {
  // We assume that the Function with the minimal number of References might be
  // the starting Function, e.g. main. If multiple Functions have the same
  // number of references, we can not be sure and return nullptr.
  Function *StartingFunction = nullptr;
  unsigned int CurrentNumReferences = UINT_MAX;
  bool SeenNumRefsTwice = false;

  for (auto &CGNode : CG) {
    auto *F = CGNode.second->getFunction();
    if(F == nullptr)
      continue;
    auto NumRef = CGNode.second->getNumReferences();
    if (NumRef < CurrentNumReferences) {
      StartingFunction = F;
      CurrentNumReferences = NumRef;
    } else if (NumRef == CurrentNumReferences) {
      SeenNumRefsTwice = true;
    }
  }
  if (SeenNumRefsTwice)
    return nullptr;
  if (DebugPrints)
    outs() << "StartingFunction: " << StartingFunction->getName() << "\n";
  return StartingFunction;
}

/**
 * @brief Iterates over MachineFunction
 *        and dumps its content into a File.
 *
 * @param F
 * @return true
 * @return false
 */
bool PathAnalysisPass::runOnMachineFunction(MachineFunction &F) {
  //if (DebugPrints) {
    outs() << "MachineFunction: " << F.getName() << "\n";
  //}

  // Get CallGraph analysis results
  if (CG == nullptr) {
    auto &CGWP = getAnalysis<CallGraphWrapperPass>();
    CG = &CGWP.getCallGraph();
    CG->print(outs());
  }

  // Get the starting function
  Function *StartingFunction = getStartingFunction(*CG);
  outs() << "StartingFunction: " << StartingFunction->getName() << "\n";
  // do the Path analysis for the starting function ONLY!
  if (F.getName().compare(StartingFunction->getName()) != 0) {
    return false;
  }

  // Get the MachineLoopInfo analysisresults
  auto &MLWP = getAnalysis<MachineLoopInfoWrapperPass>();
  auto &MLI = MLWP.getLI();

 // Create and fill MuArchGraph
  for (auto &MBB : F) {
    for (auto &MI : MBB) {
    }
  }
  // Get the ScalarEvolution analysis results
  // auto &SEWP = getAnalysis<ScalarEvolutionWrapperPass>();
  // auto &SE = SEWP.getSE();
  //SE.print(outs());

  // Get the LoopInfo analysis results
  // auto &LWP = getAnalysis<LoopInfoWrapperPass>();
  // auto &LI = LWP.getLoopInfo();
  //LI.print(outs());

  // access print the exitKind for each Loop from SCalarEveolution
  // for (auto &L : LI) {
  // // check for nested loops
  //   if (L->getLoopDepth() >= 1) {
  //     outs() << "UpperTripCnts:"<< SE.getSmallConstantMaxTripCount(L) << "\n";
  //     auto SLs = L->getSubLoops();
  //     for (auto &SL : SLs) {
  //       outs() << "SubLoop: " << SL->getHeader()->getName() << "\n";
  //       outs() << "UpperTripCnts:"<< SE.getSmallConstantMaxTripCount(L) << "\n";
  //       auto *Bound = SE.getExitCount(SL, SL->getExitBlock(), ScalarEvolution::ExitCountKind::ConstantMaximum);
  //       if (Bound) {
  //         outs() << "SLExitKind: " << *Bound << "\n";
  //       } else {
  //         outs() << "No SLExitKind\n";
  //       }
  //     }
  //   }
  //   auto *Bound = SE.getExitCount(L, L->getExitBlock(), ScalarEvolution::ExitCountKind::ConstantMaximum);
  //   if (Bound) {
  //     outs() << "ExitKind: " << *Bound << "\n";
  //   } else {
  //     outs() << "No ExitKind\n";
  //   }
  // }

  // if (DebugPrints) {
  //   outs() << "MachineLoopInfo: \n";
  //   MLI.print(outs());
  // }

  // if (DebugPrints) {
  //   outs() << "LoopInfo: \n";
  //   LI.print(outs());
  // }

  // if (DebugPrints & !LI.empty()) {
  //   outs() << "ScalarEvolution: \n";
  //   SE.print(outs());
  // }
  return false;
}

MachineFunctionPass *createPathAnalysisPass(TimingAnalysisResults &TAR) {
  return new PathAnalysisPass(TAR);
}
} // namespace llvm
