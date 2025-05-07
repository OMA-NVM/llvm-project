#include "MIRPasses/TimingAnalysisPasses.h"
#include "MIRPasses/AccessAnalyses.h"
#include "MIRPasses/AdressResolverPass.h"
#include "MIRPasses/AsmDumpAndCheckPass.h"
#include "MIRPasses/InstructionLatencyPass.h"
#include "MIRPasses/Mir2IrPass.h"
#include "MIRPasses/PathAnalysisPass.h"
#include "TimingAnalysisResults.h"

namespace llvm {

static TimingAnalysisResults TAR = TimingAnalysisResults();

std::list<MachineFunctionPass *> getTimingAnalysisPasses(TargetMachine &TM) {
  std::list<MachineFunctionPass *> Passes;
  Passes.push_back(createAsmDumpAndCheckPass(TAR));
  Passes.push_back(createAdressResolverPass(TAR));
  Passes.push_back(createInstructionLatencyPass(TAR));
  //Passes.push_back(createAccessAnalysesPass(TM));
  Passes.push_back(createPathAnalysisPass(TAR));
  Passes.push_back(createMIRtoIRPass(TAR));
  return Passes;
}

} // namespace llvm
