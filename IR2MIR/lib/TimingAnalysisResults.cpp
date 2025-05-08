#include "TimingAnalysisResults.h"

namespace llvm {

  // START: Instruction Latency Pass Containers
  void TimingAnalysisResults::setMBBLatencyMap(std::unordered_map<const MachineBasicBlock *, unsigned int> MBBLatencyMap) {
    MBBLatencyMapSet = true;
    this->MBBLatencyMap = MBBLatencyMap;
  }

  std::unordered_map<const MachineBasicBlock *, unsigned int> TimingAnalysisResults::getMBBLatencyMap() {
    assert(MBBLatencyMapSet && "MBBLatencyMap is not set, and should be set by the InstructionLatencyPass");
    return MBBLatencyMap;
  }
  // END: Instruction Latency Pass Containers


} // namespace llvm
