#include "MIRPasses/TimingAnalysisPasses.h"
#include "MIRPasses/AdressResolverPass.h"
#include "MIRPasses/AsmDumpAndCheckPass.h"

namespace llvm {

std::list<MachineFunctionPass *> getTimingAnalysisPasses(TargetMachine &TM) {
  std::list<MachineFunctionPass *> Passes;
  Passes.push_back(createAsmDumpAndCheckPass(TM));
  Passes.push_back(createAdressResolverPass(TM));
  return Passes;
}

} // namespace llvm
