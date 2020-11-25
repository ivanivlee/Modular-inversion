#!/bin/bash

echo "Counting the operations..."

gcc modifiedPenk.c -o alg1
gcc montgomery.c -o alg2
gcc LeftShift.c -o alg3
gcc AMIsubtractionFree.c -o scripts/alg4
gcc AMIsubtractions.c -o scripts/alg5
echo "Algorithms compiled."

#python3 generate.py