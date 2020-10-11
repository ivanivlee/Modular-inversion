# retrieve primes from resource/primes.txt
# generate a list


primes = [int(line.rstrip('\n')) for line in open("resource/primes.txt")]

filename =  "scripts/run.sh"
script = open(filename, "w+")
script.write("#!/bin/bash\n")
for prime in primes: 
    script.write("chmod +x {0}.sh\n".format(prime))    
for prime in primes: 
    script.write("./{0}.sh\n".format(prime))        
script.close()
print("Prepared running script in scripts/run")
    