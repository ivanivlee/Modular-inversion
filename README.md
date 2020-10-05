# Modular-inversion
Complexity analysis of binary algorithms for Modular inversion

The repo consists of two folders - 'src original algorithms' and 'counting the operations'.

## src original algorithms
This folder contains the original algorithms implemented by design in the paper. They are tested on small primes, just to ensure the quality of the implementation. 

### Compilation
- compile with `gcc LeftShift.c -o leftshift`

Modified Penk - algorithm 1
input: integer a, prime p (will have to figure out the bounds)

issues to deal with:
- binary input?
- size of the input, regarding to the size of the registers

Montgomery - algorithm 2
input: integer a, prime p

LeftShift - algorithm 3
input: integer a, prime p

TestGen: 
- program for generating test sh script for the other algorithms
- to generate set of test data, testGen.exe takes 2 arguments - size of the test data 
(integer - script will test all prime numbers lower than n) (ID of an algorithm / 1 for modified Penk, 2 for Montgomery, 3 for LeftShift)
- enter "./testGen n id"
- testGen then generates a sh file with lines of the form "a b M" where a*b = 1 mod M, compiles the given algorithm and runs it between generating trios
- n should be between 1 and 100000
- TO DO: You shouldn't check the results manually, but for now you have to. Implement comparing of the result values.

