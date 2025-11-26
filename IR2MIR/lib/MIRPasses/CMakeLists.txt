message(STATUS "Found LLVM Machine Passes LIB for IR2MIR")

add_llvm_library(ir2mirMPasses
  AsmDumpAndCheckPass.cpp
  TimingAnalysisPasses.cpp
  AdressResolverPass.cpp
  InstructionLatencyPass.cpp
  AccessAnalyses.cpp
  PathAnalysisPass.cpp
  MachineLoopBoundAgregatorPass.cpp
  Mir2IrPass.cpp
  CallSplitterPass.cpp
  DebugIRPass.cpp
  DEPENDS LLVMAnalysis LLVMCodeGen LLVMCore LLVMSupport LLVMTarget
)
