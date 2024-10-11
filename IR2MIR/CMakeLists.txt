
#building out of llvm sources  is not possible, see:
#https://lists.llvm.org/pipermail/llvm-dev/2019-March/130706.html
message (STATUS "Found tool IR2MIR")

project("ir2mir")

set(LLVM_LINK_COMPONENTS
  AllTargetsAsmParsers
  AllTargetsCodeGens
  AllTargetsDescs
  AllTargetsInfos
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  IRPrinter
  IRReader
  MC
  MIRParser
  Passes
  Remarks
  ScalarOpts
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils
  Vectorize
  )

message (STATUS "${PROJECT_BINARY_DIR}$")
message (STATUS "${PROJECT_SOURCE_DIR}$")

include_directories(include ${LLVM_BINARY_DIR}/lib/Target/ARM ${LLVM_SOURCE_DIR}/lib/Target/ARM ${LLVM_BINARY_DIR}/lib/Target/RISCV ${LLVM_SOURCE_DIR}/lib/Target/RISCV)

add_llvm_tool(ir2mir
  IR2MIR.cpp
  NewPMDriver.cpp

  DEPENDS
  intrinsics_gen
  SUPPORT_PLUGINS
  )

add_subdirectory(lib)

target_link_libraries(ir2mir PRIVATE ir2mirMPasses)


export_executable_symbols_for_plugins(ir2mir)
