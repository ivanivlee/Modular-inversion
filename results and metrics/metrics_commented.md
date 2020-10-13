## Algorithm comparison
In the beginning, a brief comparison between the three algorithms has been made. The test set included first 1899 prime numbers. Then the three algorithms were used for finding the modular inverse for all the integers from 2 do p - 1. We counted the average, minimal and maximal amount of operations such as addition, subtraction, left and right shifts and tests if a number is positive or negative.
### data format:
[test, even, add, sub, rshift, lshift]
- test: u < 0
- even: u == 0
- add: u + v
- sub: u - v
- rshift: u >> 1
- lshift: u << 1

### Algorithm 1 - modified Penk's algorithm
|    | test | even | add | sub | rshift | lshift |
| ---|---------- |-------------| -----|---|---|---|
| average: | 65.37     | 83.13     | 26.80     | 27.28     | 42.93     | 0.0 |
| min:     | 11        | 9         | 2         | 4         | 4         | 0   |
| max:     | 70        | 91        | 38        | 28        | 52        | 0   |


### Algorithm 2 - Montgomery's algorithm
|    | test | even | add | sub | rshift | lshift |
| ---|---------- |-------------| -----|---|---|---|
| average: | 37.10     | 60.47     | 33.18     | 14.98     | 44.93     | 22.46     |
| min:     | 6         | 9         | 4         | 3         | 6         | 3         |
| max:     | 41        | 80        | 39        | 16        | 54        | 27        |


### Algorithm 3 - New left shift algorithm
|    | test | even | add | sub | rshift | lshift |
| ---|---------- |-------------| -----|---|---|---|
| average: | 23.30     | 0.0 | 0.84      | 11.83     | 6.84      | 20.92     |
| min:     | 6         | 0   | 0         | 2         | 1         | 3         |
| max:     | 51        | 0   | 24        | 28        | 13        | 41        |
