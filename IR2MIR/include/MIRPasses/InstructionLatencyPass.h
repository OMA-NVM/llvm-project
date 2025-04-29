#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/Target/TargetMachine.h"

#include <cstddef>
#include <unordered_map>

namespace llvm {

/**
 * This pass sums up the instructionb Latency of each basic block in a
 * function. It is used to check if the instruction latencies are implemented.
 * TODO: The current implementation assumes that MSP430X is used.
 * It further assumes no Pipeline, which is true for the MSP430X.
 */
class InstructionLatencyPass : public MachineFunctionPass {
public:
  static char ID;
  const bool DebugPrints = false;
  TargetMachine &TM;

  std::unique_ptr<std::unordered_map<MachineBasicBlock *, unsigned int>> MBBLatencyMap;

  InstructionLatencyPass(TargetMachine &TM);

  const std::unordered_map<MachineBasicBlock *, unsigned int> &getMBBLatencyMap() const {
    return *MBBLatencyMap;
  }
  std::unordered_map<MachineBasicBlock *, unsigned int> &getMBBLatencyMap() {
    return *MBBLatencyMap;
  }

  using iterator = std::unordered_map<MachineBasicBlock *, unsigned int>::iterator;
  using const_iterator = std::unordered_map<MachineBasicBlock *, unsigned int>::const_iterator;

  // Return the function the MBBLatncyMap corresponds to.
  MachineFunction &getFunction() const {
    return *MBBLatencyMap->begin()->first->getParent();
  }

  inline iterator begin() { return MBBLatencyMap->begin(); }
  inline iterator end() { return MBBLatencyMap->end(); }
  inline const_iterator begin() const { return MBBLatencyMap->begin(); }
  inline const_iterator end() const { return MBBLatencyMap->end(); }

  // inline const std::unordered_map<MachineBasicBlock *, unsigned int> *operator[](const MachineBasicBlock *MBB) const {
  //   return (*MBBLatencyMap)[MBB].second();
  // }

  //===---------------------------------------------------------------------
  // Implementation of the ModulePass interface needed here.
  //
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  };

  // Add all missing virtual funtions from the base class

  //bool runOnMachineBasicBlock(MachineBasicBlock &MBB);
  bool runOnMachineFunction(MachineFunction &F) override;
  //bool doFinalization(Module &) override;

  virtual llvm::StringRef getPassName() const override {
    return "ARM Timing Analysis Result Dump Pass";
  }
  // bool containsPC(const MachineInstr &I);
  unsigned int getMSP430Latency(const MachineInstr &I);
};

} // namespace llvm

namespace llvm {
MachineFunctionPass *createInstructionLatencyPass(TargetMachine &TM);
} // namespace llvm
