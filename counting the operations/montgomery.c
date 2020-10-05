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

    //counters
    int add = 0;
    int sub = 0;
    int rshift = 0;
    int lshift = 0;
    int even = 0;
    int test = 0;


    while (v > 0)
    {
        test++; //while (v > 0)
        if (u % 2 == 0)
        {
            even++; //if (u % 2 == 0)
            u = u>>1;
            rshift++;
            s = s<<1; //multiply by 2 - left shift, line 5
            lshift++;
            k++;
        }
        else if (v % 2 == 0)
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            v = v>>1;
            rshift++;
            r = r<<1;
            lshift++;
            k++;
        }
        else //line 8
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            x = u - v;
            sub++;
            test++; //if (x > 0)
            if (x > 0)
            {
                u = x>>1;
                rshift++;
                r = r + s;
                add++;
                s = s<<1;
                lshift++;
                k++;
            }
            else //line 12
            {
                v = -(x>>1);
                rshift++;
                s = r + s;
                add++;
                r = r<<1;
                lshift++;
                k++;
            }
            
        }
    }
    test++; //if (r > p)
    if (r > p)
    {
        r = r - p; //line 15
        sub++;
    }
    //printf("Almost Montgomery Inverse y = %d\n", p - r);
    //Phase 2
    //almost Montgomery inverse y:
    r = p - r;
    sub++;
    for (int i = 0; i < k; i++) //k is the number of halvings from phase 1
    {
        even++;
        if (r % 2 == 0)
        {
            r = r>>1;
            rshift++;
        }
        else
        {
            r = (r + p)>>1;
            add++;
            rshift++;
        }                
    }
    //printf("Result r = %d\n", r);
    *result = r;
    *halvings = k<<1;

    printf("test = %d\n", test);
    printf("even = %d\n", even);
    printf("add = %d\n", add);
    printf("sub = %d\n", sub);
    printf("rshift = %d\n", rshift);
    printf("lshift = %d\n", lshift);

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