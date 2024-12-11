message(STATUS "Found LLVM Machine Passes LIB for IR2MIR")

add_llvm_library(ir2mirUtility
  Options.cpp
  DEPENDS LLVMAnalysis LLVMCodeGen LLVMCore LLVMSupport LLVMTarget
)
