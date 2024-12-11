#include "llvm/CodeGen/LiveIntervals.h"
#include "llvm/CodeGen/LiveStacks.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

namespace TimingAnalysisPass {

/**
 * Pass that prints the resulting assembler for the given program if option
 * enable-asm-dump is true. In any case, it checks that the program with its
 * instructions adheres to our implicit assumptions and gives reasonable error
 * messages to the user.
 */
class InstructionLatencyPass : public MachineFunctionPass {
public:
  static char ID;
  TargetMachine &TM;
  InstructionLatencyPass(TargetMachine &TM);

  bool runOnMachineBasicBlock(MachineBasicBlock &MBB);
  bool runOnMachineFunction(MachineFunction &F) override;
  bool doFinalization(Module &) override;
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  };

  virtual llvm::StringRef getPassName() const override {
    return "ARM Timing Analysis Result Dump Pass";
  }
  // bool isFormatII(const MachineInstr &I);
  // bool isFormatIII(const MachineInstr &I);
  void getMSP430Latency(const MachineInstr &I);
};

} // namespace TimingAnalysisPass

namespace llvm {
MachineFunctionPass *createInstructionLatencyPass(TargetMachine &TM);
} // namespace llvm
