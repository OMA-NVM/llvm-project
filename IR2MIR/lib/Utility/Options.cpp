#include "Utility/Options.h"

using namespace llvm;

cl::OptionCategory IR2MIRCat("0. IR2MIR Options");

cl::opt<std::string> DumpFilename(
    "dump-file", cl::init("-"),
    cl::desc("Input dump file"),
    cl::cat(IR2MIRCat));

cl::opt<std::string> StartFunctionName(
    "start-function", cl::init(""),
    cl::desc("Name of the functions to start the timing analysis from"),
    cl::cat(IR2MIRCat));
