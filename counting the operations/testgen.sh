#!/bin/bash
echo "Testing algorithm 3 ..."
gcc LeftShift.c -o alg3
echo "1 1 2"
./alg3 1 2
echo "2 2 3"
./alg3 2 3
echo "3 2 5"
./alg3 3 5
echo "3 5 7"
./alg3 3 7
