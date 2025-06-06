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


  /*output*/
  outs() << "\nBefore Splitting:\n\n";
  unsigned count = 0;
  for (auto &MBB : F){
    outs() << "MBB: " << MBB.getName() << ": \n";
    for (auto &MI : MBB) {
      outs() << "MI: " << MI << " -";
    }
    outs() << "\n";
    count++;
  }

  /*split basic blocks before and after calls*/
  for (auto &MBB : F) {

    //split block after call
    for (auto &MI : MBB) {
      if (MI.isCall()){
        MBB.splitAt(MI);
      }
    }

    //get position of instruction before call (if present)
    int position_before_call = -1;
    int counter = 0;
  
    for (auto &MI : MBB) {
      if (MI.isCall()){
        position_before_call = counter - 1;
      }
      ++counter;
    }

    //split block before call, if a call exists and is not the first instruction
    counter = 0;
    if (position_before_call >= 0){
      for (auto &MI : MBB) {
        if (counter == position_before_call){
          MBB.splitAt(MI);
        }
        ++counter;
      }
    }

  }

  /*output*/
  outs() << "\nNumber BB: " << count;
  count = 0;
  outs() << "\n\nAfter splitting:\n\n";

  for (auto &MBB : F){
    outs() << "MBB: " << MBB.getName() << ": \n";
    for (auto &MI : MBB) {
      outs() << "MI: " << MI << " -";
    }
    outs() << "\n";
    count++;
  }
  outs() << "\nNumber BB: " << count << "\n-----------------\n";

  return false;
}


MachineFunctionPass *llvm::createCallSplitterPass(TargetMachine &TM) {
  return new CallSplitterPass(TM);
}
} // namespace llvm
