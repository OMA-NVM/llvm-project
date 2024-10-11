#!/bin/bash


conf() {
  (cd IR2MIR ; cd ..) || (echo "Execute from llvm-project base folder!" ; exit)
  cmake \
    -S llvm \
    -B build\
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
    -Wno-dev \
    -Wno-suggest-override \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_ENABLE_EH=ON \
    -DLLVM_ENABLE_ASSERTIONS=ON \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_OPTIMIZED_TABLEGEN=ON \
    -DLLVM_EXTERNAL_IR2MIR_SOURCE_DIR=./IR2MIR \
    -DLLVM_EXTERNAL_PROJECTS="IR2MIR" \
    -GNinja
  cp build/compile_commands.json .
}

build() {
  cd build || (echo "No build folder found! Execute from llvm-project base folder." ; exit)
  ninja
  cd ..
}

case $1 in
config | c)
  conf
  ;;
build | b)
  build
  ;;
*)
  if [ $1 ]; then
    echo "Unknown argument: $1"
  fi
  echo "Script to configure and build:"
  echo "  c | config                 Configure for Development."
  echo "  b | build                  Build the project."
  exit
  ;;
esac
