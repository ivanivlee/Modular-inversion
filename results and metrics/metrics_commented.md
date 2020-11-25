## Algorithm comparison
In the beginning, a brief comparison between the three algorithms has been made. The test set included first 1899 prime numbers. Then the three algorithms were used for finding the modular inverse for all the integers from 2 do p - 1. We counted the average, minimal and maximal amount of operations such as addition, subtraction, left and right shifts and tests if a number is positive or negative.
### data format:
[test, add, sub, shift]
- test: u < 0
- add: u + v
- sub: u - v
- shift: u >> 1, u << 1 


### Algorithm 1 - modified Penk's algorithm
|    | test | add | sub | shift |
| ---|---------- |-------------| -----|---|
| average: | 65.37     | 26.80     | 27.28     | 42.93     |
| min:     | 11        | 2         | 4         | 4         |
| max:     | 70        | 38        | 28        | 52        |


### Algorithm 2 - Montgomery's algorithm
|    | test |add | sub | shift |
| ---|--------| -----|---|---|
| average: | 37.10     | 33.18     | 14.98     | 67.39 |
| min:     | 6         | 4         | 3         | 9   |
| max:     | 41        | 39        | 16        |81 |


### Algorithm 3 - New left shift algorithm
<<<<<<< HEAD
|    | test | even | add | sub | rshift | lshift |
| ---|---------- |-------------| -----|---|---|---|
| average: | 23.30     | 0.0 | 0.84      | 11.83     | 6.84      | 20.92     |
| min:     | 6         | 0   | 0         | 2         | 1         | 3         |
| max:     | 51        | 0   | 24        | 28        | 13        | 41        |


## Second counting:
[test, add, sub, total shifts]


=======
|    | test |  add | sub | rshift |
| ---|---------- |-------------| -----|---|
| average: | 23.30     | 0.84      | 11.83     | 27.76    |
| min:     | 6         |  0         | 2         | 4         |
| max:     | 51        |  24        | 28        | 54        |

### Algorithm 4 - New left shift algorithm
|    | test |  add | sub | rshift |
| ---|---------- |-------------| -----|---|
| average: | 23.30     | 0.84      | 11.83     | 27.76    |
| min:     | 6         |  0         | 2         | 4         |
| max:     | 51        |  24        | 28        | 54        |

### Algorithm 4 - AMI subtraction free algorithm
|    | test |  add | sub | rshift |
| ---|---------- |-------------| -----|---|


### Algorithm 5 - AMI algorithm with subtractions
|    | test |  add | sub | rshift |
| ---|---------- |-------------| -----|---|
>>>>>>> refs/remotes/origin/master
