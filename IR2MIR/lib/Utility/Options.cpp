#include "Utility/Options.h"

using namespace llvm;

cl::OptionCategory IR2MIRCat("0. IR2MIR Options");

cl::opt<std::string> DumpFilename(
    "dump-file", cl::init("-"),
    cl::desc("Input dump file"),
    cl::cat(IR2MIRCat));
