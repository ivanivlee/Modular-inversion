# retrieve primes from resource/primes.txt
# generate a list
# loop through the numbers and generate a .sh script inbash to run the algorithms with proper arguments


primes = [int(line.rstrip('\n')) for line in open("resource/primes.txt")]

#this will loop through all the primes
#primes = [3, 5, 7, 11] 

for prime in primes: 
    filename =  "scripts/" + str(prime) + ".sh"
    print(filename)
    script = open(filename, "w+")
    script.write("#!/bin/bash\n")
    for i in range(2, prime):
        #script.write("alg1 {0} {1}\n".format(i, prime))
        #script.write("alg2 {0} {1}\n".format(i, prime))
        #script.write("alg3 {0} {1}\n".format(i, prime))
        script.write("./alg4 {0} {1}\n".format(i, prime))
        script.write("./alg5 {0} {1}\n".format(i, prime))
    #print("Running script generated for prime {}".format(prime))
    script.close()

    