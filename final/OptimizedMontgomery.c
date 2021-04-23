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

int trailingZeros(NUM x)
{
    if (x == 0)
    {
        return 0;
    }
    
    int zeros = 0;
    while ((x % 2) == 0)
    {
        x = x >> 1;
        zeros++;
    }
    return zeros;
}

int precompute(NUM  n, NUM p)
{
    int T = 1;
    for (int i = 0; i < 2*n; i++)
    {
        if (T % 2 == 1)
        {
            T = T + p;
        }
        T >> 2;
    }
    return T;
}

int sizeOfNumber(NUM n)
{
    int count = 0; 
    while (n) 
    { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 


NUM OM(NUM a, NUM p) //the real algorithm is in this function - Almost Montgomery Algorithm
{
    NUM u = -p;
    NUM v = a;
    NUM r = 0;
    NUM s = 1;
    NUM k = 0;
    NUM x = 0;
    NUM y = 0;
    NUM tlzX = 0;
    NUM n = sizeOfNumber(p);
    NUM T = precompute(n, p);

     //counters
    int add = 0;
    int sub = 0;
    int shift = 0;
    int even = 0;
    int test = 0;
    int zero = 0;
    int neg = 0;
    int loop = 0;
    

    //Phase I
    while (1)
    {
        x = u + v;
        printf("%d\n", x);
        y = r + s;
        tlzX = (trailingZeros(x));
        printf("x%d, y%d, %d\n", x, y, tlzX);
        if (x == 0)
        {
            //Phase II
            s = (s << (2*n - k)) % p;
            s =  (s*T) % p;
            printf("%d, %d, %d, %d\n", a, s, p, k);
            return 0;
        }
        else if (x < 0)
        {
            u = x >> tlzX;
            r = y;
            s = s << tlzX;
            printf("u=%d, %d, %d, %d\n", u, r, s, k);
        }
        else
        {
            v = x >> tlzX;
            s = y;
            r = r << tlzX; 
            printf("v=%d, %d, %d, %d\n", v, r, s, k); 
        }
        k = k + tlzX;
        printf("%d\n", k);
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

    OM(a,p);
    return 0;
}
