#ifndef TIMING_ANALYSIS_RESULTS_H
#define TIMING_ANALYSIS_RESULTS_H

#include "llvm/CodeGen/MachineBasicBlock.h"
#include <unordered_map>
namespace llvm {

//===- TimingAnalysisResults.h - Timing Analysis Results -------*- C++ -*-===//
// This class amkes all Timing Analysis results available between TimingAnalysisPasses.
// It is used to store the results of the Timing Analysis passes.
class TimingAnalysisResults {
public:

    // START: Instruction Latency Pass Containers
    std::unordered_map<const MachineBasicBlock *, unsigned int> MBBLatencyMap;
    bool MBBLatencyMapSet = false;

    void setMBBLatencyMap(std::unordered_map<const MachineBasicBlock *, unsigned int> MBBLatencyMap);

    std::unordered_map<const MachineBasicBlock *, unsigned int> getMBBLatencyMap();
    // END: Instruction Latency Pass Containers
};

} // namespace llvm

#endif // TIMING_ANALYSIS_RESULTS_H
