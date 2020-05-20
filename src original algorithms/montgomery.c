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


int montgomery(int a, int p, int *result, int *halvings) //the real algorithm is in this function 
{
    //Phase 1
    int u = p;
    int v = a;
    int r = 0;
    int s = 1;
    int k = 0; //line 2 - init
    int x = 0;
    while (v > 0)
    {
        if (u % 2 == 0)
        {
            u = u>>1;
            s = s<<1; //multiply by 2 - left shift, line 5
            k++;
        }
        else if (v % 2 == 0)
        {
            v = v>>1;
            r = r<<1;
            k++;
        }
        else //line 8
        {
            x = u - v;
            if (x > 0)
            {
                u = x>>1;
                r = r + s;
                s = s<<1;
                k++;
            }
            else //line 12
            {
                v = -(x>>1);
                s = r + s;
                r = r<<1;
                k++;
            }
            
        }
    }
    if (r > p)
    {
        r = r - p; //line 15
    }
    //printf("Almost Montgomery Inverse y = %d\n", p - r);
    //Phase 2
    //almost Montgomery inverse y:
    r = p - r;
    for (int i = 0; i < k; i++) //k is the number of halvings from phase 1
    {
        if (r % 2 == 0)
        {
            r = r>>1;
        }
        else
        {
            r = (r + p)>>1;
        }                
    }
    //printf("Result r = %d\n", r);
    *result = r;
    *halvings = k<<1;
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
    
    montgomery(a, p, &result, &halvings); //THEREALALGORITHM
    printf("%d %d %d\n", a, result, p);

    
    return 0;
}