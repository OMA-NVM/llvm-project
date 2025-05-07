#ifndef TIMING_ANALYSIS_RESULTS_H
#define TIMING_ANALYSIS_RESULTS_H

#include "llvm/CodeGen/MachineBasicBlock.h"
#include <memory>
#include <unordered_map>
namespace llvm {

//===- TimingAnalysisResults.h - Timing Analysis Results -------*- C++ -*-===//
// This class amkes all Timing Analysis results available between TimingAnalysisPasses.
// It is used to store the results of the Timing Analysis passes.
class TimingAnalysisResults {
public:
    std::unique_ptr<std::unordered_map<MachineBasicBlock *, unsigned int>> MBBLatencyMap = nullptr;

    void setMBBLatencyMap(std::unique_ptr<std::unordered_map<MachineBasicBlock *, unsigned int>> MBBLatencyMap) {
        this->MBBLatencyMap = std::move(MBBLatencyMap);
    }

    std::unique_ptr<std::unordered_map<MachineBasicBlock *, unsigned int>> getMBBLatencyMap() {
        return std::move(MBBLatencyMap);
    }
};

} // namespace llvm

#endif // TIMING_ANALYSIS_RESULTS_H
