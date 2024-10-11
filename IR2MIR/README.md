# IR2MIR

## LLVM Documentation to look at for MIR passes

1. [MIR Format](https://llvm.org/docs/MIRLangRef.html)
2. [Instruction Selection Pipeline](https://llvm.org/docs/GlobalISel/Pipeline.html)
3. [Code Generator](https://llvm.org/docs/CodeGenerator.html)
   1. [Machine Basic Block](https://llvm.org/docs/GlobalISel/Pipeline.html) IR -> MIR is one to many mappoing.
4. [SourceLevelDebugging](https://llvm.org/docs/SourceLevelDebugging.html)
5. [Accurate LLVM IR to Binary CFGs Mapping for Simulation of Optimized Embedded Software](https://dl.acm.org/doi/10.1007/978-3-031-04580-6_1)

## Looking at

[MachineVerifier.cpp](https://github.com/llvm/llvm-project/blob/main/llvm/lib/CodeGen/MachineVerifier.cpp)

[MachineFunctionAnalysis.cpp](https://github.com/llvm/llvm-project/blob/main/llvm/lib/CodeGen/MachineFunctionAnalysis.cpp)

[Analysis.cpp](https://github.com/llvm/llvm-project/blob/main/llvm/lib/CodeGen/Analysis.cpp)

## Issues IR -> MIR Mapping:
![text](https://llvm.org/docs/_images/pipeline-overview.png)
![text](https://llvm.org/docs/_images/pipeline-overview-with-combiners.png)
LLVM Pipeline for refference of IR to MIR: [CorePipeline](https://llvm.org/docs/GlobalISel/IRTranslator.html)

#### 1. IR -> gMIR Mapping
IR is mapped to gMIR with the [IRTranslator](https://llvm.org/docs/GlobalISel/IRTranslator.html).
The mapping is not kept!
Quick link to [IRTranslator.cpp](dependencies/llvm-18.1.4.src/lib/CodeGen/GlobalISel/IRTranslator.cpp)

#### 2. gMIR -> MIR Mapping
It seems that MIR is created from gMIR in multiple passes, which are also Target dependent.
Therefore, creating a mapping between gMIR and MIR is not trivial!

#### B. IR-CFG to MIR-CFG Mapping
Reasonable?

## ToDos

- [x] Get MachinFunctionPass to run
- [ ] Add DebugIR pass to the project
- [ ] Generate Mapping between IR and MIR with the help of Debug Info
- [ ] Explore Jit Compilation instead of using object-dump on linked binary

## Build IR2MIR

This branch should come with vscode config and build Task.
However, these are the commands used.

Config:
```cmake -S llvm -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DLLVM_ENABLE_RTTI=ON -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_ASSERTIONS=ON -DLLVM_INCLUDE_BENCHMARKS=OFF -DLLVM_INCLUDE_TESTS=OFF -DLLVM_OPTIMIZED_TABLEGEN=ON -DLLVM_EXTERNAL_IR2MIR_SOURCE_DIR=./IR2MIR -DLLVM_EXTERNAL_PROJECTS='IR2MIR' -GNinja ; cp build/compile_commands.json .```

Build:
```cd build ; ninja```

## Using IR2MIR
HyWcet is a clone of [llc](https://llvm.org/docs/CommandGuide/llc.html) and injects its own passes and therefore extends on it.
To use HyWcet, you need to build it and then use it as you would use llc.
Example programs can be found in the tests folder, which have to be build with clang.


```clang -S -emit-llvm source.c -o output.ll```

Then HyWCET can be used on the resulting .ll file.

```./HyWcet output.ll```

Some parameters for debugging are quite helpfull:

1. --stats, Print statistics recorded by code-generation passes.
2. --time-passes, Print the amount of time each pass takes to execute.
