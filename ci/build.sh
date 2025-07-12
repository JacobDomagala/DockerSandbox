#!/bin/bash
source_dir=$1
build_dir=$2

ccache -s

mkdir -p "${build_dir}"
cd "${build_dir}" || exit 1

cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache "${source_dir}"
make

ccache -s
