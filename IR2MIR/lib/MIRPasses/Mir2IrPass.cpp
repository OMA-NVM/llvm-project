#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/DebugLoc.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct MIRtoIRPass : public MachineFunctionPass {
        static char ID;
        MIRtoIRPass() : MachineFunctionPass(ID) {}

        bool runOnMachineFunction(MachineFunction &MF) override {
            errs() << "Processing Machine Function: " << MF.getName() << "\n";

            MachineRegisterInfo &MRI = MF.getRegInfo(); // To track virtual registers

            for (MachineBasicBlock &MBB : MF) {
                for (MachineInstr &MI : MBB) {
                    errs() << "MachineInstr: " << MI << "\n";

                    // Retrieve IR instruction using DebugLoc
                    if (MI.getDebugLoc()) {
                        DebugLoc DL = MI.getDebugLoc();
                        const DILocation *DIL = DL.get();
                        if (DIL) {
                            errs() << "  ↳ Corresponding LLVM IR Location: "
                                   << DIL->getFilename() << ":" << DIL->getLine() << "\n";
                        }
                    }

                    // Track virtual register definitions back to IR
                    for (const MachineOperand &MO : MI.operands()) {
                        if (MO.isReg() && llvm::Register::isVirtualRegister(MO.getReg())) {
                            unsigned VReg = MO.getReg();
                            if (MachineInstr *DefMI = MRI.getVRegDef(VReg)) {
                                errs() << "  ↳ Defined by Virtual Register in: " << *DefMI << "\n";
                            }
                        }
                    }
                }
            }
            return false; // No modification to the MachineFunction
        }
    };
}

char MIRtoIRPass::ID = 0;
static RegisterPass<MIRtoIRPass> X("mir-to-ir", "Map Machine Instructions to LLVM IR", false, false);
