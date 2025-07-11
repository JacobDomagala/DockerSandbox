#!/bin/bash

mkdir -p build
cd build || exit 1
rm -rf ./*

cmake -DCMAKE_CXX_COMPILER="ccache g++" \
      ..
make


ccache -s
