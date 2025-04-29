#include "MIRPasses/TimingAnalysisPasses.h"
#include "MIRPasses/AccessAnalyses.h"
#include "MIRPasses/AdressResolverPass.h"
#include "MIRPasses/AsmDumpAndCheckPass.h"
#include "MIRPasses/InstructionLatencyPass.h"
#include "MIRPasses/Mir2IrPass.h"
#include "MIRPasses/PathAnalysisPass.h"

namespace llvm {

std::list<MachineFunctionPass *> getTimingAnalysisPasses(TargetMachine &TM) {
  std::list<MachineFunctionPass *> Passes;
  Passes.push_back(createAsmDumpAndCheckPass(TM));
  Passes.push_back(createAdressResolverPass(TM));
  Passes.push_back(createInstructionLatencyPass(TM));
  //Passes.push_back(createAccessAnalysesPass(TM));
  Passes.push_back(createPathAnalysisPass(TM));
  Passes.push_back(createMIRtoIRPass(TM));
  return Passes;
}

} // namespace llvm
