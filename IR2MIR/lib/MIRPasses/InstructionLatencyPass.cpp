#include "MIRPasses/InstructionLatencyPass.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/TargetParser/Triple.h"
#include <cassert>

#include "MCTargetDesc/MSP430MCTargetDesc.h"

using namespace llvm;

namespace TimingAnalysisPass {

char InstructionLatencyPass::ID = 0;

/**
 * @brief Construct a new Asm Dump And Check Pass:: Asm Dump And Check Pass
 * object
 *
 * @param TM
 */
InstructionLatencyPass::InstructionLatencyPass(TargetMachine &TM)
    : MachineFunctionPass(ID), TM(TM) {}

/**
 * @brief Checks if unknown Instructions were found.
 *        Always returns false.
 *
 * @return false
 */
bool InstructionLatencyPass::doFinalization(Module &M) { return false; }

/**
 * @brief Iterates over MachineFunction
 *        and dumps its content into a File.
 *
 * @param F
 * @return true
 * @return false
 */
bool InstructionLatencyPass::runOnMachineFunction(MachineFunction &F) {
  auto Arch = TM.getTargetTriple().getArch();
  for (auto &MBB : F) {
    for (auto &MI : MBB) {
      switch (Arch) {
      case Triple::ArchType::msp430:
        getMSP430Latency(MI);
        break;
      default:
        errs() << "Unknown Arch: " << Arch;
        assert(false && "not implemented");
      }
    }
  }
  return false;
}

bool isFormatII(const MachineInstr &I) {
  switch (I.getOpcode()) {
  // Format-II Instructions
  case MSP430::RRA16m:
  case MSP430::RRA16n:
  case MSP430::RRA16p:
  case MSP430::RRA16r:
  case MSP430::RRA8m:
  case MSP430::RRA8n:
  case MSP430::RRA8p:
  case MSP430::RRA8r:
  case MSP430::RRC16m:
  case MSP430::RRC16n:
  case MSP430::RRC16p:
  case MSP430::RRC16r:
  case MSP430::RRC8m:
  case MSP430::RRC8n:
  case MSP430::RRC8p:
  case MSP430::RRC8r:
  case MSP430::SWPB16m:
  case MSP430::SWPB16n:
  case MSP430::SWPB16p:
  case MSP430::SWPB16r:
  case MSP430::CALLi:
  case MSP430::CALLm:
  case MSP430::CALLn:
  case MSP430::CALLp:
  case MSP430::CALLr:
  case MSP430::POP16r:
  case MSP430::PUSH16c:
  case MSP430::PUSH16i:
  case MSP430::PUSH16r:
  case MSP430::PUSH8r:
    return true;
  default:
    return false;
  }
}

bool isFormatIII(const MachineInstr &I) {
  switch (I.getOpcode()) {
  // Format-III Instructions
  case MSP430::Bi:
  case MSP430::Bm:
  case MSP430::Br:
  case MSP430::JMP:
  case MSP430::RET:
  case MSP430::RETI:
  // Conditional branches
  case MSP430::JCC:
    return true;
  default:
    return false;
  }
}

void InstructionLatencyPass::getMSP430Latency(const MachineInstr &I) {
  // Latecy Information found here:
  // https://www.ti.com/lit/ug/slau144k/slau144k.pdf?ts=1733402836810
  if (isFormatII(I)) {
    // Handle Format-II instructions

  } else if (isFormatIII(I)) {
    // Handle Format-III Instructions

  } else {
    // Handle Format-I Instructions
    // outs() << I;
    for (unsigned int Num=0 ; Num < I.getNumOperands() ; Num++){
      // outs() << "Dump operand[" << Num << "]: " << I.getOperand(Num) << ", ";
    }
    // outs() << "\n\n";
  }
}
} // namespace TimingAnalysisPass

MachineFunctionPass *llvm::createInstructionLatencyPass(TargetMachine &TM) {
  return new TimingAnalysisPass::InstructionLatencyPass(TM);
}
