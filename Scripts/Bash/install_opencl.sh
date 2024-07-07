#!/bin/bash
# OpenCL does not work in WSL
# https://github.com/microsoft/WSL/issues/6951
mkdir -p 3rdPartyPackages/neo
cd 3rdPartyPackages/neo

wget https://github.com/intel/intel-graphics-compiler/releases/download/igc-1.0.16900.23/intel-igc-core_1.0.16900.23_amd64.deb
wget https://github.com/intel/intel-graphics-compiler/releases/download/igc-1.0.16900.23/intel-igc-opencl_1.0.16900.23_amd64.deb
wget https://github.com/intel/compute-runtime/releases/download/24.22.29735.20/intel-level-zero-gpu-dbgsym_1.3.29735.20_amd64.ddeb
wget https://github.com/intel/compute-runtime/releases/download/24.22.29735.20/intel-level-zero-gpu_1.3.29735.20_amd64.deb
wget https://github.com/intel/compute-runtime/releases/download/24.22.29735.20/intel-opencl-icd-dbgsym_24.22.29735.20_amd64.ddeb
wget https://github.com/intel/compute-runtime/releases/download/24.22.29735.20/intel-opencl-icd_24.22.29735.20_amd64.deb
wget https://github.com/intel/compute-runtime/releases/download/24.22.29735.20/libigdgmm12_22.3.19_amd64.deb

sudo apt update
sudo apt -y install ocl-icd-libopencl1 clinfo intel-gpu-tools

sudo dpkg -i *.deb

# Fix any missing dependencies
sudo apt -f install

rm *.deb