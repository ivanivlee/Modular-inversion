# retrieve primes from resource/primes.txt
# generate a list
# loop through the numbers and generate a .sh script inbash to run the algorithms with proper arguments


primes = [int(line.rstrip('\n')) for line in open("resource/primes.txt")]

script = open("counting.sh", "w")
f.write("Now the file has more content!")


for prime in primes:
    for i in range(2, prime):
        script.write(alg1)

script.close()