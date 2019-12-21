#!/bin/bash

cp -vf ../awtk-binding/tools/code_gen/cpp/output/*.hpp src
cp -vf ../awtk-binding/tools/code_gen/cpp/output/*.cpp src

. format.sh
