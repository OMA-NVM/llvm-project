#include "MIRPasses/PathAnalysisPass.h"
#include "TimingAnalysisResults.h"
#include "Utility/Options.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/ScalarEvolutionAliasAnalysis.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include <cassert>
#include <gurobi_c++.h>
#include <memory>
#include <vector>

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
    if(!StartFunctionName.empty() && F->getName().compare(StartFunctionName)) {
      return F;
    }
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
  if (DebugPrints)
    outs() << "MachineFunction: " << F.getName() << "\n";

  if(!CG) {
    CG = &getAnalysis<CallGraphWrapperPass>().getCallGraph();
  }
  if (!FoundStartingFunction) {
    StartingFunction = getStartingFunction(*CG);
    // Get the starting function if the StartingFunctionName is empty
    if (!StartingFunction) {
      outs() << "No StartingFunction found\n";
    }
    assert(StartingFunction && "StartingFunction is null");
  }

  // Get the MachineLoopInfo analysisresults
  auto &MLWP = getAnalysis<MachineLoopInfoWrapperPass>();
  auto &MLI = MLWP.getLI();
  //outs() << "MachineLoopInfo: \n";
  //MLI.print(outs());

  // Get the Latency analysis results
  auto MBBLatencyMap = TAR.getMBBLatencyMap();

  // Fill MuArchGraph Nodes
  for (auto &MBB : F) {
    //interate over MIs in MBB and find calling Instructions
    for (auto &MI : MBB) {
      if (MI.isCall()) {
        if (true){
          // split MBB before and after the call
          outs() << "MBB: " << MBB.getName() << ", MBB size: " << MBB.size() << "\n";
          outs() << "Found Call Instruction: " << "in Function: " << F.getName() << "\n";
          MI.getOperand(0).dump();
          // split MBB before and after the call
          //TODO add inter function edge to graph
        }
      }
    }
    // Create a new MuArchStateGraph and add ti the graph as unique ptr
    MASG.addNode(MuArchState(MBBLatencyMap[&MBB], MBBLatencyMap[&MBB]), &MBB);
  }
  // Fill MuArchGraph Edges
  for (auto &MBB : F) {
    for (auto &Succ : MBB.successors()) {
      //if (Succ->getParent() == MBB.getParent()){
        unsigned FromNode = MASG.MBBToNodeMap[&MBB];
        unsigned ToNode = MASG.MBBToNodeMap[Succ];
        MASG.addEdge(FromNode, ToNode);
        //}

    }
  }
  return false;
}

MachineFunctionPass *createPathAnalysisPass(TimingAnalysisResults &TAR) {
  return new PathAnalysisPass(TAR);
}
} // namespace llvm
