#!/usr/bin/env bash

mkdir -p out/Debug
cd out/Debug
cmake -GNinja ../..
ninja
