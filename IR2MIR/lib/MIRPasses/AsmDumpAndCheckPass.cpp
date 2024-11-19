#include "MIRPasses/AsmDumpAndCheckPass.h"
#include "llvm/Analysis/CFGPrinter.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/GraphWriter.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/TargetParser/Triple.h"
#include <cassert>

#include "MCTargetDesc/MSP430MCTargetDesc.h"
#include "MSP430.h"

using namespace llvm;

namespace TimingAnalysisPass {

char AsmDumpAndCheckPass::ID = 0;

/**
 * @brief Construct a new Asm Dump And Check Pass:: Asm Dump And Check Pass
 * object
 *
 * @param TM
 */
AsmDumpAndCheckPass::AsmDumpAndCheckPass(TargetMachine &TM)
    : MachineFunctionPass(ID), TM(TM) {}

/**
 * @brief Checks if unknown Instructions were found.
 *        Always returns false.
 *
 * @return false
 */
bool AsmDumpAndCheckPass::doFinalization(Module &) { return false; }

/**
 * @brief Iterates over MachineFunction
 *        and dumps its content into a File.
 *
 * @param F
 * @return true
 * @return false
 */
bool AsmDumpAndCheckPass::runOnMachineFunction(MachineFunction &F) {
  auto Arch = TM.getTargetTriple().getArch();
  for (auto &MBB : F) {
    for (auto &MI : MBB) {
      switch (Arch) {
      case Triple::ArchType::msp430:
        checkMSP430Instruction(MI);
        break;
      default:
        errs() << "Unknown Arch: " << Arch;
        assert(false && "not implemented");
      }
    }
  }
  return false;
}

/**
 * @brief Calls checkInstruction on all Instructions in MBB.
 *
 * @param MBB
 * @return true
 * @return false
 */
bool AsmDumpAndCheckPass::runOnMachineBasicBlock(MachineBasicBlock &MBB) {
  // TODO get the BBToMBB mapping fron the IRTranslatorPass
  // and get the corresponding IR BB.
  for (auto &MI : MBB) {
    // print MI
    MI.dump();
    // if (MI.isPseudo()) {
    // outs() << "Found pseudo instruction: ";
    // MI.dump();
    //}
  }
  return false;
}

void AsmDumpAndCheckPass::checkMSP430Instruction(const MachineInstr &I) {
  bool FoundPseudoInstruction = false;
  switch (I.getOpcode()) {

  case MSP430::ADD16mc:
  case MSP430::ADD16mi:
  case MSP430::ADD16mm:
  case MSP430::ADD16mn:
  case MSP430::ADD16mp:
  case MSP430::ADD16mr:
  case MSP430::ADD16rc:
  case MSP430::ADD16ri:
  case MSP430::ADD16rm:
  case MSP430::ADD16rn:
  case MSP430::ADD16rp:
  case MSP430::ADD16rr:
  case MSP430::ADD8mc:
  case MSP430::ADD8mi:
  case MSP430::ADD8mm:
  case MSP430::ADD8mn:
  case MSP430::ADD8mp:
  case MSP430::ADD8mr:
  case MSP430::ADD8rc:
  case MSP430::ADD8ri:
  case MSP430::ADD8rm:
  case MSP430::ADD8rn:
  case MSP430::ADD8rp:
  case MSP430::ADD8rr:
  case MSP430::ADDC16mc:
  case MSP430::ADDC16mi:
  case MSP430::ADDC16mm:
  case MSP430::ADDC16mn:
  case MSP430::ADDC16mp:
  case MSP430::ADDC16mr:
  case MSP430::ADDC16rc:
  case MSP430::ADDC16ri:
  case MSP430::ADDC16rm:
  case MSP430::ADDC16rn:
  case MSP430::ADDC16rp:
  case MSP430::ADDC16rr:
  case MSP430::ADDC8mc:
  case MSP430::ADDC8mi:
  case MSP430::ADDC8mm:
  case MSP430::ADDC8mn:
  case MSP430::ADDC8mp:
  case MSP430::ADDC8mr:
  case MSP430::ADDC8rc:
  case MSP430::ADDC8ri:
  case MSP430::ADDC8rm:
  case MSP430::ADDC8rn:
  case MSP430::ADDC8rp:
  case MSP430::ADDC8rr:
  case MSP430::AND16mc:
  case MSP430::AND16mi:
  case MSP430::AND16mm:
  case MSP430::AND16mn:
  case MSP430::AND16mp:
  case MSP430::AND16mr:
  case MSP430::AND16rc:
  case MSP430::AND16ri:
  case MSP430::AND16rm:
  case MSP430::AND16rn:
  case MSP430::AND16rp:
  case MSP430::AND16rr:
  case MSP430::AND8mc:
  case MSP430::AND8mi:
  case MSP430::AND8mm:
  case MSP430::AND8mn:
  case MSP430::AND8mp:
  case MSP430::AND8mr:
  case MSP430::AND8rc:
  case MSP430::AND8ri:
  case MSP430::AND8rm:
  case MSP430::AND8rn:
  case MSP430::AND8rp:
  case MSP430::AND8rr:
  case MSP430::BIC16mc:
  case MSP430::BIC16mi:
  case MSP430::BIC16mm:
  case MSP430::BIC16mn:
  case MSP430::BIC16mp:
  case MSP430::BIC16mr:
  case MSP430::BIC16rc:
  case MSP430::BIC16ri:
  case MSP430::BIC16rm:
  case MSP430::BIC16rn:
  case MSP430::BIC16rp:
  case MSP430::BIC16rr:
  case MSP430::BIC8mc:
  case MSP430::BIC8mi:
  case MSP430::BIC8mm:
  case MSP430::BIC8mn:
  case MSP430::BIC8mp:
  case MSP430::BIC8mr:
  case MSP430::BIC8rc:
  case MSP430::BIC8ri:
  case MSP430::BIC8rm:
  case MSP430::BIC8rn:
  case MSP430::BIC8rp:
  case MSP430::BIC8rr:
  case MSP430::BIS16mc:
  case MSP430::BIS16mi:
  case MSP430::BIS16mm:
  case MSP430::BIS16mn:
  case MSP430::BIS16mp:
  case MSP430::BIS16mr:
  case MSP430::BIS16rc:
  case MSP430::BIS16ri:
  case MSP430::BIS16rm:
  case MSP430::BIS16rn:
  case MSP430::BIS16rp:
  case MSP430::BIS16rr:
  case MSP430::BIS8mc:
  case MSP430::BIS8mi:
  case MSP430::BIS8mm:
  case MSP430::BIS8mn:
  case MSP430::BIS8mp:
  case MSP430::BIS8mr:
  case MSP430::BIS8rc:
  case MSP430::BIS8ri:
  case MSP430::BIS8rm:
  case MSP430::BIS8rn:
  case MSP430::BIS8rp:
  case MSP430::BIS8rr:
  case MSP430::BIT16mc:
  case MSP430::BIT16mi:
  case MSP430::BIT16mm:
  case MSP430::BIT16mn:
  case MSP430::BIT16mp:
  case MSP430::BIT16mr:
  case MSP430::BIT16rc:
  case MSP430::BIT16ri:
  case MSP430::BIT16rm:
  case MSP430::BIT16rn:
  case MSP430::BIT16rp:
  case MSP430::BIT16rr:
  case MSP430::BIT8mc:
  case MSP430::BIT8mi:
  case MSP430::BIT8mm:
  case MSP430::BIT8mn:
  case MSP430::BIT8mp:
  case MSP430::BIT8mr:
  case MSP430::BIT8rc:
  case MSP430::BIT8ri:
  case MSP430::BIT8rm:
  case MSP430::BIT8rn:
  case MSP430::BIT8rp:
  case MSP430::BIT8rr:
  case MSP430::CMP16mc:
  case MSP430::CMP16mi:
  case MSP430::CMP16mm:
  case MSP430::CMP16mn:
  case MSP430::CMP16mp:
  case MSP430::CMP16mr:
  case MSP430::CMP16rc:
  case MSP430::CMP16ri:
  case MSP430::CMP16rm:
  case MSP430::CMP16rn:
  case MSP430::CMP16rp:
  case MSP430::CMP16rr:
  case MSP430::CMP8mc:
  case MSP430::CMP8mi:
  case MSP430::CMP8mm:
  case MSP430::CMP8mn:
  case MSP430::CMP8mp:
  case MSP430::CMP8mr:
  case MSP430::CMP8rc:
  case MSP430::CMP8ri:
  case MSP430::CMP8rm:
  case MSP430::CMP8rn:
  case MSP430::CMP8rp:
  case MSP430::CMP8rr:
  //The DADD instruction needs 1 extra cycle.
  case MSP430::DADD16mc:
  case MSP430::DADD16mi:
  case MSP430::DADD16mm:
  case MSP430::DADD16mn:
  case MSP430::DADD16mp:
  case MSP430::DADD16mr:
  case MSP430::DADD16rc:
  case MSP430::DADD16ri:
  case MSP430::DADD16rm:
  case MSP430::DADD16rn:
  case MSP430::DADD16rp:
  case MSP430::DADD16rr:
  case MSP430::DADD8mc:
  case MSP430::DADD8mi:
  case MSP430::DADD8mm:
  case MSP430::DADD8mn:
  case MSP430::DADD8mp:
  case MSP430::DADD8mr:
  case MSP430::DADD8rc:
  case MSP430::DADD8ri:
  case MSP430::DADD8rm:
  case MSP430::DADD8rn:
  case MSP430::DADD8rp:
  case MSP430::DADD8rr:
  //End DADD
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
  case MSP430::SEXT16m:
  case MSP430::SEXT16n:
  case MSP430::SEXT16p:
  case MSP430::SEXT16r:
  case MSP430::SUB16mc:
  case MSP430::SUB16mi:
  case MSP430::SUB16mm:
  case MSP430::SUB16mn:
  case MSP430::SUB16mp:
  case MSP430::SUB16mr:
  case MSP430::SUB16rc:
  case MSP430::SUB16ri:
  case MSP430::SUB16rm:
  case MSP430::SUB16rn:
  case MSP430::SUB16rp:
  case MSP430::SUB16rr:
  case MSP430::SUB8mc:
  case MSP430::SUB8mi:
  case MSP430::SUB8mm:
  case MSP430::SUB8mn:
  case MSP430::SUB8mp:
  case MSP430::SUB8mr:
  case MSP430::SUB8rc:
  case MSP430::SUB8ri:
  case MSP430::SUB8rm:
  case MSP430::SUB8rn:
  case MSP430::SUB8rp:
  case MSP430::SUB8rr:
  case MSP430::SUBC16mc:
  case MSP430::SUBC16mi:
  case MSP430::SUBC16mm:
  case MSP430::SUBC16mn:
  case MSP430::SUBC16mp:
  case MSP430::SUBC16mr:
  case MSP430::SUBC16rc:
  case MSP430::SUBC16ri:
  case MSP430::SUBC16rm:
  case MSP430::SUBC16rn:
  case MSP430::SUBC16rp:
  case MSP430::SUBC16rr:
  case MSP430::SUBC8mc:
  case MSP430::SUBC8mi:
  case MSP430::SUBC8mm:
  case MSP430::SUBC8mn:
  case MSP430::SUBC8mp:
  case MSP430::SUBC8mr:
  case MSP430::SUBC8rc:
  case MSP430::SUBC8ri:
  case MSP430::SUBC8rm:
  case MSP430::SUBC8rn:
  case MSP430::SUBC8rp:
  case MSP430::SUBC8rr:
  case MSP430::SWPB16m:
  case MSP430::SWPB16n:
  case MSP430::SWPB16p:
  case MSP430::SWPB16r:
  case MSP430::XOR16mc:
  case MSP430::XOR16mi:
  case MSP430::XOR16mm:
  case MSP430::XOR16mn:
  case MSP430::XOR16mp:
  case MSP430::XOR16mr:
  case MSP430::XOR16rc:
  case MSP430::XOR16ri:
  case MSP430::XOR16rm:
  case MSP430::XOR16rn:
  case MSP430::XOR16rp:
  case MSP430::XOR16rr:
  case MSP430::XOR8mc:
  case MSP430::XOR8mi:
  case MSP430::XOR8mm:
  case MSP430::XOR8mn:
  case MSP430::XOR8mp:
  case MSP430::XOR8mr:
  case MSP430::XOR8rc:
  case MSP430::XOR8ri:
  case MSP430::XOR8rm:
  case MSP430::XOR8rn:
  case MSP430::XOR8rp:
  case MSP430::XOR8rr:
  case MSP430::ZEXT16r:

  // Call Instructions
  case MSP430::CALLi:
  case MSP430::CALLm:
  case MSP430::CALLn:
  case MSP430::CALLp:
  case MSP430::CALLr:

  // Move Instructions
  case MSP430::MOV16mc:
  case MSP430::MOV16mi:
  case MSP430::MOV16mm:
  case MSP430::MOV16mn:
  case MSP430::MOV16mr:
  case MSP430::MOV16rc:
  case MSP430::MOV16ri:
  case MSP430::MOV16rm:
  case MSP430::MOV16rn:
  case MSP430::MOV16rp:
  case MSP430::MOV16rr:
  case MSP430::MOV8mc:
  case MSP430::MOV8mi:
  case MSP430::MOV8mm:
  case MSP430::MOV8mn:
  case MSP430::MOV8mr:
  case MSP430::MOV8rc:
  case MSP430::MOV8ri:
  case MSP430::MOV8rm:
  case MSP430::MOV8rn:
  case MSP430::MOV8rp:
  case MSP430::MOV8rr:
  case MSP430::MOVZX16rm8:
  case MSP430::MOVZX16rr8:

  // Miscellaneous Instructions
  case MSP430::POP16r:
  case MSP430::PUSH16c:
  case MSP430::PUSH16i:
  case MSP430::PUSH16r:
  case MSP430::PUSH8r:

  // Control Flow Instructions
  case MSP430::Bi:
  case MSP430::Bm:
  case MSP430::Br:
  case MSP430::JMP:
  case MSP430::RET:
  case MSP430::RETI:
  //Conditional branches
  case MSP430::JCC:
    break;

  case MSP430::Rrcl16:   // Pseudo
  case MSP430::Rrcl8:    // Pseudo
  case MSP430::Select16: // Pseudo
  case MSP430::Select8:  // Pseudo
  case MSP430::Shl16:    // Pseudo
  case MSP430::Shl8:     // Pseudo
  case MSP430::Sra16:    // Pseudo
  case MSP430::Sra8:     // Pseudo
  case MSP430::Srl16:    // Pseudo
  case MSP430::Srl8:     // Pseudo
    errs() << "PSEUDO Inst: " << I << "\n";
    assert(0 && "Found pseudo instruction");
    break;
  default:
    errs() << "UNKNOWN: " << I << "\n";
    assert(0 && "Found unknown instruction");
    break;
  }
}
} // namespace TimingAnalysisPass

MachineFunctionPass *llvm::createAsmDumpAndCheckPass(TargetMachine &TM) {
  return new TimingAnalysisPass::AsmDumpAndCheckPass(TM);
}
