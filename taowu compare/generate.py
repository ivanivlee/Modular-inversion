# retrieve primes from resource/primes.txt
# generate a list
# loop through the numbers and generate a .sh script inbash to run the algorithms with proper arguments


primes = [int(line.rstrip('\n')) for line in open("resource/primes.txt")]

#this will loop through all the primes


for prime in primes: 
    filename =  "scripts/" + str(prime) + ".sh"
    print(filename)
    script = open(filename, "w+")
    script.write("#!/bin/bash\n")
    for i in range(2, prime):
        #script.write("./a1 {0} {1}\n".format(i, prime))
        #script.write("./a2 {0} {1}\n".format(i, prime))
        #script.write("./a3 {0} {1}\n".format(i, prime))
        #script.write("./a4 {0} {1}\n".format(i, prime))
        #script.write("./a5 {0} {1}\n".format(i, prime))
        script.write("./a6 {0} {1}\n".format(i, prime))
    #print("Running script generated for prime {}".format(prime))
    script.close()

    