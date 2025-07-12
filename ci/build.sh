#!/bin/bash

set -ex
source_dir=$1
build_dir=$2

CCACHE_DIR=/build/.ccache


ccache -s

mkdir -p "${build_dir}"
cd "${build_dir}" || exit 1

cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache "${source_dir}"
make

ccache -s

if [ "${CI_BUILD:-0}" = "1" ]; then
  CI_CCACHE_DIR=/build/ci/.ccache
  mkdir -p "${CI_CCACHE_DIR}"
  cp -a "${CCACHE_DIR}/." "${CI_CCACHE_DIR}/"
fi
