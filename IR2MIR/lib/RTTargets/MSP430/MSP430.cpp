//===-- MSP430.cpp - MSP430 Target Implementation ------------------------===//
#include "llvm/CodeGen/MachineInstr.h"
#include "RTTargets/MuArchStateGraph.h"
#include <cassert>
namespace llvm {


struct MSP430MuArchState : public MuArchState {
  MachineInstr &MI;        // Reference to the corresponding MachineInstr
  unsigned int Lat;        // Latency produced by the instruction
  // TODO Add FRAM Cache State

  // Constructor to initialize the Node
  MSP430MuArchState(MachineInstr &Inst, unsigned int Lat)
    : MuArchState(Lat, Lat), MI(Inst), Lat(Lat) {}
};

} // end namespace llvm
