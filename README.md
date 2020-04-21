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
- program for generating test sh script for the other algorithms
- to generate set of test data, testGen.exe takes 2 arguments - size of the test data 
(integer - script will test all prime numbers lower than n) (ID of an algorithm / 1 for modified Penk, 2 for Montgomery, 3 for LeftShift)
- enter "./testGen n id"
- testGen then generates a sh file with lines of the form "a b M" where a*b = 1 mod M, compiles the given algorithm and runs it between generating trios
- n should be between 1 and 100000
- TO DO: You shouldn't check the results manually, but for now you have to. Implement comparing of the result values.
