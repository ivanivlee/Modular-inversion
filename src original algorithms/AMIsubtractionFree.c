#include <stdio.h>
#include<stdlib.h>
#include <math.h> 

typedef signed short NUM; //the basic data type for all the operations / has to be signed!

// variables and data types
NUM a, p; //from input

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
int inputSizeCheck(NUM a, NUM p)    //checks whether 1 <= a <= p or not
{
     if (a < 1)
    {
        printf("Argument a is too small. \n");
        return 1;
    }
    if (a > p)
    {
        printf("Argument a is too big. \n");
        return 1;
    }
    return 0;
}


NUM ami(NUM a, NUM p) //the real algorithm is in this function - Almost Montgomery Algorithm
{
    NUM u = -p;
    NUM v = a;
    NUM r = 0;
    NUM s = 1;
    NUM k = 0;
    NUM x = 0;
    NUM y = 0;

    while(1)
    {
        if(u % 2 == 0)
        {
            u = u>>1;
            s = s<<1;
        }
        else if (v % 2 == 0)
        {
            v = v>>1;
            r = r<<1;
        }
        else
        {
            x = u + v;
            y = r + s;
            if (x == 0)
            {
                printf("ami = %d, k = %d\n", s, k);
                return (0);
            }
            if (x < 0)
            {
                u = x>>1;
                r = y;
                s = s<<1;
            }
            else 
            {
                v = x>>1;
                s = y;
                r = r<<1;
            }  
        }
        k++;
    }
}
// in: integer a, prime p, 1 <= a <= p - two parametres from terminal
int main(int argc, char* argv[])
{
    //check and prepare input
    if (inputCountCheck(argc) == 1){return 1;}
    a = atoi(argv[1]); // convert to int
    p = atoi(argv[2]); 
    if (inputSizeCheck(a, p) == 1){return 1;}

    ami(a,p);
    return 0;
}
