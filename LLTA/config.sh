#!/bin/bash


conf() {
  (cd LLTA ; cd ..) || (echo "Execute from llvm-project base folder!" ; exit)
  CC=clang CXX=clang++ cmake \
    -S llvm \
    -B build \
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
  cp build/compile_commands.json .
}

build() {
  cd build || (echo "No build folder found! Execute from llvm-project base folder." ; exit)
  ninja llta
  cd ..
}

build_all() {
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
buildall | build-all | ba)
  build_all
  ;;
*)
  if [ $1 ]; then
    echo "Unknown argument: $1"
  fi
  echo "Script to configure and build:"
  echo "  c | config                 Configure for Development."
  echo "  b | build                  Build the llta target."
  echo "  ba| build-all              Build all targets."
  exit
  ;;
esac
