message(STATUS "Found LLVM Machine Passes LIB for IR2MIR")

add_llvm_library(ir2mirRTTargets
  MSP430/MSP430.cpp
  MuArchStateGraph.cpp
  DEPENDS LLVMAnalysis LLVMCodeGen LLVMCore LLVMSupport LLVMTarget
)
