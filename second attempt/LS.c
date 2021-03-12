#include <stdio.h>
#include<stdlib.h>

typedef signed short NUM; 
NUM a, p; //input - element a, prime p

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
int bin(NUM n, NUM length) //display binary of SIGNED NUM
{ 
    NUM i;  
    int size = 8*(sizeof(NUM));
    (n < 0)? printf("1 "): printf("0 "); 
    for (i = 1 << (length - 1); i > 0; i = i / 2) // size - 1 if unsigned, size - 2 if signed
        (n & i)? printf("1 "): printf("0 ");  
    printf("\n");
    return 0;
} 
int sizeOfTheBiggerNumber(NUM u, NUM v)
{
    int n = (v < u) ? u : v;  
    int count = 0; 
    while (n) 
    { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 
int bit(NUM n, int bit) //value of nth MSB bit
{
        n = (n >> bit);
        if (n % 2 == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
}
int bits(NUM n, int bit) //how many bits 0, 1, ... n are still zeros - valuation of two in this number
{
        for (size_t i = 0; i < bit+1; i++)
        {
            //printf("\nn = %d", n);
            if ((n % 2) != 0)
            {   
                //printf("1");
                return 1;
            }
            n = (n >> 1);
        }
        
        //printf("0");
        return 0;
}
int LS(NUM a , NUM p)
{
    //line 1, 2 - initialize
    NUM u = p;
    NUM v = a;
    NUM r = 0;
    NUM s = 1;
    //NUM cu = 0;
    //NUM cv = 0;
    //mask registers
    NUM Rmu = 1; //2^cu
    NUM Rmv = 1; //2^cv
    //size n
    NUM size = sizeOfTheBiggerNumber(u,v);
    //line 3 - while loop
    while (((u^Rmu) != 0) && ((u+Rmu) != 0) && ((v^Rmv) != 0) && ((v+Rmv) != 0))
    {
        printf("u = %d, ", u); bin(u, size);
        printf("v = %d, ", v); bin(v, size);
        printf("r = %d, ", r); bin(r, size);
        printf("s = %d, ", s); bin(s, size);
        printf("_______________________________________________________________________________________________________\n");
        if ((bit(u, size) == 0 && bit(u, size-1) == 0)|| ((bit(u, size) == 1 && bit(u, size-1) == 1) && (bits(u, size-2) == 1)))
        {
            //printf("posuv u\n");
            u = (u<<1);
            if (Rmu >= Rmv)   { r = (r<<1);} else { s = (s>>1);}
            Rmu = (Rmu<<1);
        }
        else if ((bit(v, size) == 0 && bit(v, size-1) == 0)|| ((bit(v, size) == 1 && bit(v, size-1) == 1) && (bits(v, size-2) == 1)))
        {
            //printf("posuv v\n");
            v = (v<<1);
            if (Rmv >= Rmu)   { s = (s<<1);} else { r = (r>>1);}
            Rmv = (Rmv<<1);
        }
        else
        {
            //printf("oper\n");
            NUM oper; //0 is minus, 1 is plus
            if (bit(u, size) == bit(v, size)) //check if the signs are the same
            {
                oper = 0; //minus
            }
            else
            {
                oper = 1; //plus
            }
            //printf("oper = %d\n", oper);
            if (Rmu <= Rmv)
            {
                //printf("cu <= cv\n");
                u = (oper == 0) ? (u - v) : (u + v);
                r = (oper == 0) ? (r - s) : (r + s);
            }
            else
            {
                //printf("cv <= cu\n");
                v = (oper == 0) ? (v - u) : (v + u);
                s = (oper == 0) ? (s - r) : (s + r);
            }
        } 
    }
    printf("u = %d, ", u); bin(u, size);
    printf("v = %d, ", v); bin(v, size);
    printf("r = %d, ", r); bin(r, size);
    printf("s = %d, ", s); bin(s, size);
    //printf("Rmu = ");bin(Rmu, size);
    //printf("Rmv = ");bin(Rmv, size);
    if (((v^Rmv) == 0) || ((v+Rmv) == 0))
    {
        r = s;
        u = v;
    }
    if (u < 0)
    {
        if (r < 0)
        {
            r = -r;
        }
        else
        {
            r = p - r;
        }
    }
    if (r < 0)
    {
        r = r + p;  
    }
    printf("%d %d %d \n", a, r, p);
    printf("%d * %d = %d mod %d", a, r, (a*r)%p, p);
    return 0;
}










int main(int argc, char* argv[])
{
    //check and prepare input
    if (inputCountCheck(argc) == 1){return 1;}
    a = atoi(argv[1]); // convert to int
    p = atoi(argv[2]); 
    if (inputSizeCheck(a, p) == 1){return 1;}
    
    LS(a, p);

    return 0;
}