#!/bin/bash

mkdir -p build
cd build || exit 1
rm rf ./*

cmake CMAKE_CXX_COMPILER="ccache g++" ..
make
