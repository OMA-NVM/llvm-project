#ifndef LLVM_IR2MIR_MIRPASSES_INSTRUCTIONLATENCYPASS_H
#define LLVM_IR2MIR_MIRPASSES_INSTRUCTIONLATENCYPASS_H

#include "TimingAnalysisResults.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/Target/TargetMachine.h"

#include <cstddef>
#include <unordered_map>

namespace llvm {

/**
 * This pass sums up the instruction Latency of each basic block in a
 * function. It is used to check if the instruction latencies are implemented.
 * TODO: The current implementation assumes that MSP430X is used.
 * It further assumes no Pipeline, which is true for the MSP430X.
 */
class InstructionLatencyPass : public MachineFunctionPass {
public:
  static char ID;
  const bool DebugPrints = false;
  TimingAnalysisResults &TAR;

  std::unique_ptr<std::unordered_map<MachineBasicBlock *, unsigned int>> MBBLatencyMap;

  InstructionLatencyPass(TimingAnalysisResults &TAR);

  const std::unordered_map<MachineBasicBlock *, unsigned int> &getMBBLatencyMap() const {
    return *MBBLatencyMap;
  }
  std::unordered_map<MachineBasicBlock *, unsigned int> &getMBBLatencyMap() {
    return *MBBLatencyMap;
  }

  using iterator = std::unordered_map<MachineBasicBlock *, unsigned int>::iterator;
  using const_iterator = std::unordered_map<MachineBasicBlock *, unsigned int>::const_iterator;

  MachineFunction &getFunction() const {
    return *MBBLatencyMap->begin()->first->getParent();
  }

  inline iterator begin() { return MBBLatencyMap->begin(); }
  inline iterator end() { return MBBLatencyMap->end(); }
  inline const_iterator begin() const { return MBBLatencyMap->begin(); }
  inline const_iterator end() const { return MBBLatencyMap->end(); }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  };

  bool runOnMachineFunction(MachineFunction &F) override;

  virtual llvm::StringRef getPassName() const override {
    return "ARM Timing Analysis Result Dump Pass";
  }

  unsigned int getMSP430Latency(const MachineInstr &I);
};


MachineFunctionPass *createInstructionLatencyPass(TimingAnalysisResults &TAR);
} // namespace llvm

#endif // LLVM_IR2MIR_MIRPASSES_INSTRUCTIONLATENCYPASS_H
