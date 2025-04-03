#include "MIRPasses/PathAnalysisPass.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <gurobi_c++.h>

namespace llvm {

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

Function *PathAnalysisPass::getStartingFunction(CallGraph &CG) {
  // We assume that the Function with the minimal number of References might be
  // the starting Function, e.g. main. If multiple Functions have the same
  // number of references, we can not be sure and return nullptr.
  Function *StartingFunction = nullptr;
  unsigned int CurrentNumReferences = INTMAX_MAX;
  bool SeenNumRefsTwice = false;

  for (auto &CGNode : CG) {
    auto *F = CGNode.second->getFunction();
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
  if (DebugPrints) {
    outs() << "MachineFunction: " << F.getName() << "\n";
  }

  // Get CallGraph analysis results
  if (CG == nullptr) {
    auto &CGWP = getAnalysis<CallGraphWrapperPass>();
    CG = &CGWP.getCallGraph();
    // CG->print(outs());
    //  Iterate over CallGraph
  }

  // Get the MachineLoopInfo analysisresults
  auto &MLWP = getAnalysis<MachineLoopInfoWrapperPass>();
  auto &MLI = MLWP.getLI();

  // Get the ScalarEvolution analysis results
  auto &SEWP = getAnalysis<ScalarEvolutionWrapperPass>();
  auto &SE = SEWP.getSE();

  // Get the LoopInfo analysis results
  auto &LWP = getAnalysis<LoopInfoWrapperPass>();
  auto &LI = LWP.getLoopInfo();
  LI.print(outs());

  // access print the exitKind for each Loop from SCalarEveolution
  for (auto &L : LI) {
  // check for nested loops
    if (L->getLoopDepth() > 1) {
      auto SL = L->getSubLoops();
      for (auto &S : SL) {
        outs() << "SubLoop: " << S->getHeader()->getName() << "\n";
        auto *Bound = SE.getExitCount(S, S->getExitBlock(), ScalarEvolution::ExitCountKind::ConstantMaximum);
        if (Bound) {
          outs() << "SLExitKind: " << *Bound << "\n";
        } else {
          outs() << "No SLExitKind\n";
        }
      }
    }
    auto *Bound = SE.getExitCount(L, L->getExitBlock(), ScalarEvolution::ExitCountKind::ConstantMaximum);
    if (Bound) {
      outs() << "ExitKind: " << *Bound << "\n";
    } else {
      outs() << "No ExitKind\n";
    }
  }

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

MachineFunctionPass *createPathAnalysisPass(TargetMachine &TM) {
  return new PathAnalysisPass(TM);
}
} // namespace llvm
