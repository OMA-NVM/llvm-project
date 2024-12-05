#ifndef IR2MIR_ADRESS_RESOLVER_H
#define IR2MIR_ADRESS_RESOLVER_H
#include "llvm/CodeGen/MachineFunctionPass.h"
using namespace llvm;

namespace TimingAnalysisPass {
class AdressResolverPass : public MachineFunctionPass {
public:
  static char ID;
  TargetMachine &TM;
  AdressResolverPass(TargetMachine &TM);

  // PreservedAnalyses run(Module &M, ModuleAnalysisManager &MAM);
  bool runOnMachineBasicBlock(MachineBasicBlock &MBB);
  bool runOnMachineFunction(MachineFunction &F) override;
  bool doFinalization(Module &) override;
  bool doInitialization(Module &) override;

  void parseFile(std::string Filename);
  bool parseLine(std::string Line, int LineNumber);
  int lineHasLineNumber(std::string Line);
  bool isHex(std::string &In);
  void getAnalysisUsage(AnalysisUsage &AU) const override {
    // AU.addUsedIfAvailable<LiveStacks>();
    // AU.addUsedIfAvailable<LiveVariables>();
    // AU.addUsedIfAvailable<SlotIndexes>();
    // AU.addUsedIfAvailable<LiveIntervals>();
    AU.setPreservesCFG();
    AU.setPreservesAll();
    MachineFunctionPass::getAnalysisUsage(AU);
  };

  virtual llvm::StringRef getPassName() const override {
    return "Adress Resolver Pass";
  }
};
} // namespace TimingAnalysisPass

namespace llvm {
MachineFunctionPass *createAdressResolverPass(TargetMachine &TM);
} // namespace llvm
#endif
