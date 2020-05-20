#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h> 


#define MAXCOUNT 100000 // the type is unsigned long, this number should be less than uint max.

unsigned int count;
int algorithm;

int advice()
{
    printf("Expected usage: ./testgen <upper bound for the size of the primes> <ID of the algorithm>\nEnter 1 for modified Penk, 2 for Montgomery, 3 for LeftShift.\n");
    printf("Upper bound should be between 1 and 100000.\n");
    return 0;
}

int inputCountCheck(int argCount)    //checks number of arguments, should be 2 - count and ID of algorithm
{
    if (argCount > 3)   
    {
        printf("Too many arguments. \n");
        advice();
        return 1;
    }
    if (argCount < 3)   
    {
        printf("Too few arguments. \n");
        advice();
        return 1;
    }
    return 0;
}

int inputSizeCheck(unsigned int count)    //checks whether 1 <= count <= maxcount or not
{
    if (count < 2)
    {
        printf("Integer a is too small, should be at least 2. \n");
        advice();
        return 1;
    }
    if (count > MAXCOUNT)
    {
        printf("Integer a is too big. Max count is %d. \n", MAXCOUNT);
        advice();
        return 1;
    }
    return 0;

}

unsigned int inverseGen(unsigned int modulo, unsigned int element) //generates inverse number to the element modulo this prime number
{ 
    for (unsigned int x = 1; x < modulo; x++) 
       if ((element * x) % modulo == 1) 
          return x; 
       
    return 0; 
}

int testGen(unsigned int num, FILE *fp, int alg)
{
    int flag = 0;
    unsigned int element = 0;
    unsigned int inverse = 0;
    srand(time(0)); 

    for (unsigned long i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) 
        {
            element = rand() % num;
            if (element == 0)
            {
                element = 1;
            }
            inverse = inverseGen(num, element);
            unsigned int test = (element * inverse) % num;
            //printf("Element = %d, inverse = %d, modulo prime = %d. Test = %d.\n", element, inverse, num, test); 
            fprintf(fp, "echo \"%d %d %d\"\n", element, inverse, num);
            fprintf(fp, "./alg%d %d %d\n", alg, element, num);
        }
    return 0;
}

int fileGen (unsigned int count, int alg) //generates test data and stores them in a txt file
{
    FILE * fPtr;
    fPtr = fopen("testgen.sh", "w");
    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fPtr, "#!/bin/bash\n");
    fprintf(fPtr, "echo \"Testing algorithm %d ...\"\n", alg);
    switch (alg)
    {
    case 1:
        fprintf(fPtr, "gcc modifiedPenk.c -o alg1\n");
        break;
    case 2:
        fprintf(fPtr, "gcc montgomery.c -o alg2\n");
        break;
    default:
        fprintf(fPtr, "gcc LeftShift.c -o alg3\n");
        break;
    }
    
    for (unsigned int j = 2; j < count; j++)
    {
        testGen(j, fPtr, alg);
    }

    fclose(fPtr);
    
    /* Success message */
    printf("File testgen.sh created and saved successfully. :) \n");
    printf("Now enter 'chmod +x testgen.sh' and './testgen.sh' \n");
    return 0;
}

int main(int argc, char* argv[])
{
    //check and prepare input
    if (inputCountCheck(argc) == 1){return 1;}
    count = atoi(argv[1]); // convert to int
    algorithm = atoi(argv[2]);
    if (inputSizeCheck(count) == 1){return 1;}

    fileGen(count, algorithm);
    //printf("%u\n", count);
    
    return 0;
}