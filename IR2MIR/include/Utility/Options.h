#ifndef UTIL_OPTIONS_H
#define UTIL_OPTIONS_H


#include "llvm/Support/CommandLine.h"

/**
 * Path to the dumo file for Adress Resolving
 */
extern llvm::cl::opt<std::string> DumpFilename;

#endif
