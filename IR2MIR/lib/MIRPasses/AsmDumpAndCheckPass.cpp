#include "MIRPasses/AsmDumpAndCheckPass.h"
#include "llvm/CodeGen/GlobalISel/IRTranslator.h"
#include "llvm/Support/raw_ostream.h"
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
  outs() << "Function: " << F.getName() << "\n";
  F.viewCFG();
  int Nr = 0;
  for (auto &MBB : F) {
    // errs() << "Basic Block: " << Nr++ << "\n\n";
    for (auto &MI : MBB) {
      // MI.print(errs(), true, false);
      // errs() << "\n";
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
} // namespace TimingAnalysisPass

MachineFunctionPass *llvm::createAsmDumpAndCheckPass(TargetMachine &TM) {
  return new TimingAnalysisPass::AsmDumpAndCheckPass(TM);
}
