#ifndef LLVM_MIR_TO_IR_PASS_H
#define LLVM_MIR_TO_IR_PASS_H

#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineLoopInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class MIRtoIRPass : public MachineFunctionPass {
public:
  static char ID;

  const bool DebugPrints = false;
  TargetMachine &TM;
  MIRtoIRPass(TargetMachine &TM);

  bool runOnMachineBasicBlock(MachineBasicBlock &MBB);
  bool runOnMachineFunction(MachineFunction &F) override;
  bool doFinalization(Module &) override;
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  };
  virtual llvm::StringRef getPassName() const override {
    return "Map Machine Instructions to LLVM IR";
  }
};
} // namespace llvm

#endif // LLVM_MIR_TO_IR_PASS_H

namespace llvm {
MachineFunctionPass *createMIRtoIRPass(TargetMachine &TM);
} // namespace llvm
