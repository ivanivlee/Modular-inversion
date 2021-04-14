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

     //counters
    int add = 0;
    int sub = 0;
    int shift = 0;
    int even = 0;
    int test = 0;
    int zero = 0;
    int neg = 0;
    int loop = 0;
    

    while(1)
    {
        loop++;
        
        if(u % 2 == 0)
        {
            even++;
            u = u>>1; shift++; 
            s = s<<1; shift++;
        }
        else if (v % 2 == 0)
        {
            even++;even++;
            v = v>>1; shift++;
            r = r<<1; shift++;
        }
        else
        {
            even++;even++;
            x = u + v; add++;
            y = r + s; add++;
            zero++;
            if (x == 0)
            {
                FILE *fp;
                fp = fopen("a5.txt", "a");
                fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", a, r, p, shift, add, sub, test, zero, neg, loop, even, k);
                fclose(fp);
                return (0);
            }
            zero++;
            if (x < 0)
            {
                u = x>>1; shift++;
                r = y;
                s = s<<1; shift++;
            }
            else 
            {
                v = x>>1; shift++;
                s = y;
                r = r<<1; shift++;
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
