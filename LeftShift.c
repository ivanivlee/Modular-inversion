#include <stdio.h>
#include<stdlib.h>


// variables and data types
unsigned int a, p; //from input
int result, halvings;

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

int leftshift(int a, int p, int *result, int *halvings) //the real algorithm is in this function 
{
    //Phase 1
    int u = p;
    int v = a;
    int r = 0;
    int s = 1; //init
    int cu = 0;
    int cv = 0;

    while (u != (2^cu) && u != -(2^cu) && v != (2^cv) && v != -(2^cv))
    {
       
    }
    

    
    return 0;
}



// in: integer a, prime p, 1 <= a <= p - two parametres from terminal
int main(int argc, char* argv[])
{
    //check and prepare input
    if (inputCountCheck(argc) == 1){return 1;}
    a = atoi(argv[1]); // convert to int
    p = atoi(argv[2]); 
    if (inputSizeCheck(a, p) == 1){return 1;}
    
    leftshift(a, p, &result, &halvings); //THEREALALGORITHM
    printf("Result r = %d, k = %d \n", result, halvings);

    
    return 0;
}