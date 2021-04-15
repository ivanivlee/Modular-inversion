avg = [0,0,0,0,0,0,0,0,0,0,0]
minval = [1000, 1000, 1000, 1000,1000, 1000, 1000, 1000,1000, 1000, 1000,1000, 1000]
maxval = [0,0,0,0,0,0,0,0,0,0,0]
filename = "a6.txt"
with open(filename) as results:
    for line in results:
        content = line.split()
        for i in range(0,10):
            #total[i] = total[i] + int(content[i + 4])
            avg[i] = (avg[i] + int(content[i + 4]))/2
            minval[i] = min(minval[i], int(content[i + 4]))
            maxval[i] = max(maxval[i], int(content[i + 4]))
    #print(total)
    print(avg)
    print(minval)
    print(maxval)
results.close()