#include <stdio.h>
#include<stdlib.h>

int inputCountCheck(int argCount)    //checks number of arguments 
{
    if (argCount > 3)   
    {
        printf("Too many arguments. \n");
        return 1;
    }
    if (argCount < 3)   
    {
        printf("Too few arguments. \n");
        return 1;
    }
    return 0;
}

int inputSizeCheck(int a, int p)    //checks whether 1 <= a <= p or not
{
     if (a < 1)
    {
        printf("Integer a is too small. \n");
        return 1;
    }
    if (a > p)
    {
        printf("Integer a is too big. \n");
        return 1;
    }
    return 0;
}

// in: integer a, prime p, 1 <= a <= p - two parametres from terminal
int main(int argc, char* argv[])
{
    //check and prepare input
    if (inputCountCheck(argc) == 1){return 1;}
    int a = atoi(argv[1]); // convert to int
    int p = atoi(argv[2]); 
    if (inputSizeCheck(a, p) == 1){return 1;}
    
    printf("Integer a = %s \n", argv[1]);
    printf("Prime p = %s \n", argv[2]);
    
    
    
    return 0;
}