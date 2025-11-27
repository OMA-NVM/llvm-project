# LLTA - Low Level Timing Analysis

LLTA is a timing analysis infrastructure built on top of LLVM. It operates on the Machine Intermediate Representation (MIR) to perform Worst-Case Execution Time (WCET) analysis. It functions as a drop-in replacement for `llc` (LLVM Static Compiler) with additional analysis passes injected into the code generation pipeline.

## Project Structure

The project is organized as follows:

- **`LLTA.cpp`**: The main driver tool, based on LLVM's `llc`.
- **`lib/MIRPasses/`**: Contains the core analysis passes that operate on MIR.
- **`lib/RTTargets/`**: Contains target-specific micro-architectural models (currently MSP430).
- **`lib/Utility/`**: Helper utilities and options.
- **`clang-plugin/`**: A Clang plugin (`LoopBoundPlugin`) for annotating loop bounds in C source code.
- **`tests/`**: Benchmarks and test scripts.

## Prerequisites

- **LLVM**: This project is designed to be built as an external project within the LLVM source tree.
- **Gurobi Optimizer**: Required for the Path Analysis pass (ILP solving).
- **Clang**: For compiling C code to LLVM IR.
- **CMake & Ninja**: Build system.

## Building

LLTA is built as part of the LLVM build process.

### 1. Configure

Run the configuration command from the root of the `llvm-project`:

```bash
CC=clang CXX=clang++ cmake -S llvm -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_OPTIMIZED_TABLEGEN=ON \
    -DLLVM_TARGETS_TO_BUILD='MSP430' \
    -DLLVM_EXTERNAL_LLTA_SOURCE_DIR=./LLTA \
    -DLLVM_EXTERNAL_PROJECTS='LLTA' \
    -DLLVM_ENABLE_PROJECTS='clang' \
    -DLLVM_USE_LINKER=lld \
    -GNinja
```

### 2. Build

```bash
cd build
ninja llta
```

To build the Clang plugin as well (required for tests):

```bash
ninja LoopBoundPlugin
```

## Usage

### 1. Running LLTA

`llta` is used similarly to `llc`. It takes an LLVM IR file (`.ll` or `.bc`) as input.

```bash
./build/bin/llta <input.ll> [options]
```

**Common Options:**

- `-march=<arch>`: Specify target architecture (e.g., `msp430`).
- `-dump-file=<path>`: Path to dump the ELF file or analysis results.
- `-start-function=<name>`: Entry point for analysis (default: `main`).

### 2. Preparing Input Files

For the analysis to work correctly, especially Loop Bound detection, the input LLVM IR must be in a canonical form.

**Recommended Optimization:**
Use `opt` to prepare your `.ll` files:

```bash
opt -passes='mem2reg,instcombine,loop-simplify,loop-rotate,indvars' input.ll -S -o input_opt.ll
```

*Note: `loop-rotate` is critical for ScalarEvolution (SCEV) to detect loop bounds.*

### 3. Annotating Loop Bounds

For loops where SCEV cannot determine bounds, use the `LoopBoundPlugin` and pragmas in your C code:

```c
#pragma loop_bound(1, 10)
for (int i = 0; i < n; i++) { ... }
```

See `LLTA/clang-plugin/README.md` for details.

## Analysis Passes

LLTA injects several passes into the backend pipeline:

1. **`MachineLoopBoundAgregatorPass`**: Collects loop bounds from SCEV and manual annotations (JSON).
2. **`InstructionLatencyPass`**: Assigns execution latency to each machine instruction based on the target model.
3. **`FillMuGraphPass`**: Constructs a graph representing the micro-architectural state.
4. **`PathAnalysisPass`**: Formulates the WCET problem as an Integer Linear Program (ILP) and solves it using Gurobi.
5. **`AdressResolverPass`**: Resolves symbolic addresses to physical addresses.
6. **`CallSplitterPass`**: Manages context sensitivity by splitting function calls.
7. **`AsmDumpAndCheckPass`**: Verifies the generated assembly against expected output.

## Supported Targets

- **MSP430**: Full support including micro-architectural modeling.

## Testing

Tests are located in `LLTA/tests/`.

To generate loop bounds for a test case:

```bash
./LLTA/tests/generate_loop_bounds.sh msp430 cnt
```

To run a debug session (VS Code):

1. Select "dbg cnt MSP430" in the Run and Debug view.
2. Press F5.
