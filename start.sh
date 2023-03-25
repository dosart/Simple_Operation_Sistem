#!/bin/bash

if [ ! -d "./build" ]; then
  echo "Directory build DOES NOT exists.\n"
  echo "mkdir build"
  mkdir "build"
fi

make
qemu-system-x86_64 -kernel build/kernel
