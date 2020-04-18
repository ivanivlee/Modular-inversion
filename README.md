# Modular-inversion
Complexity analysis of binary algorithms for Modular inversion


Modified Penk - algorithm 1\
input: integer a, prime p (will have to figure out the bounds)
issues to deal with:
- binary input?
- size of the input, regarding to the size of the registers


Compilation
- compile with `gcc LeftShift.c -o leftshift`

TestGen: 
- program for generating test data for the other algorithms
- to generate set of test data, testGen.exe takes 1 argument - size of the test data.
- to generate n lines of test data, enter "./testGen.exe n"
- testGen then generates a txt file with n lines of the form "a b M" where a*b = 1 mod M
- n should be between 1 and 100000
