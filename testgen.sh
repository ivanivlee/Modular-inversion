#!/bin/bash
echo "Testing algorithm 2 ..."
gcc montgomery.c -o alg2
echo "1 1 2"
./alg2 1 2
echo "1 1 3"
./alg2 1 3
echo "2 3 5"
./alg2 2 5
echo "1 1 7"
./alg2 1 7
echo "4 3 11"
./alg2 4 11
echo "1 1 13"
./alg2 1 13
echo "11 14 17"
./alg2 11 17
echo "13 3 19"
./alg2 13 19
echo "1 1 23"
./alg2 1 23
echo "7 25 29"
./alg2 7 29
echo "1 1 31"
./alg2 1 31
echo "17 24 37"
./alg2 17 37
echo "25 23 41"
./alg2 25 41
echo "1 1 43"
./alg2 1 43
echo "37 14 47"
./alg2 37 47
echo "32 5 53"
./alg2 32 53
echo "7 17 59"
./alg2 7 59
echo "41 3 61"
./alg2 41 61
echo "30 38 67"
./alg2 30 67
echo "9 8 71"
./alg2 9 71
echo "55 4 73"
./alg2 55 73
echo "9 44 79"
./alg2 9 79
echo "77 69 83"
./alg2 77 83
echo "17 21 89"
./alg2 17 89
echo "47 64 97"
./alg2 47 97
