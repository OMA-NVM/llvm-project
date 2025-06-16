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
CallSplitterPass::CallSplitterPass(TimingAnalysisResults &TAR)
    : MachineFunctionPass(ID), TAR(TAR) {}

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

  /*output basic blocks before splitting*/
  unsigned count = 0;
  if(DebugPrints){
    outs() << "\nBefore Splitting:\n\n";
    for (auto &MBB : F){
      outs() << "MBB: " << MBB.getName() << ": \n";
      for (auto &MI : MBB) {
        outs() << "MI: " << MI << " -";
      }
      outs() << "\n";
      count++;
    }
  }
  

  /*split basic blocks before and after calls*/
  for (auto &MBB : F) {

    /*split block after call*/
    for (auto &MI : MBB) {
      if (MI.isCall()){
        MBB.splitAt(MI);
      }
    }

    /*get position of instruction before call (if present)*/
    int position_before_call = -1;
    int counter = 0;

    for (auto &MI : MBB) {
      if (MI.isCall()){
        position_before_call = counter - 1;
      }
      ++counter;
    }

    /*split block before call, if a call exists and is not the first instruction*/
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

  /*output basic blocks after splitting*/
  if(DebugPrints){
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
  }
  

  return false;
}


MachineFunctionPass *createCallSplitterPass(TimingAnalysisResults &TAR) {
  return new CallSplitterPass(TAR);
}
} // namespace llvm
