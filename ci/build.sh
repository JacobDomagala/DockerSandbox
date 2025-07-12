#!/bin/bash
source_dir=$1
build_dir=$2

CCACHE_DIR=/build/.ccache
CI_CCACHE_DIR=/build/ci/.ccache

ccache -s

mkdir -p "${build_dir}"
cd "${build_dir}" || exit 1

cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache "${source_dir}"
make

ccache -s

mkdir -p ${CI_CCACHE_DIR}
cp -p ${CCACHE_DIR}/ ${CI_CCACHE_DIR}/

ls -a
