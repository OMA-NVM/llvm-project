#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/Target/TargetMachine.h"
#include <list>

namespace llvm {

std::list<MachineFunctionPass *> getTimingAnalysisPasses(TargetMachine &TM);

} // namespace llvm
