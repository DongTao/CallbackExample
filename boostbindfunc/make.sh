#!/bin/bash

g++ graphics.cpp -I. -fPIC -shared -pthread -o libgraphics.so
g++ main.cpp -I. -L. -lgraphics
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
./a.out
