#include <stdio.h>
#include<stdlib.h>
//#include <math.h> 

typedef signed short NUM; 
NUM a, p; //from input
//NUM result, halvings; //to store the result and counter of halvings

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
int bit(NUM n, int bit)
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
int TW(NUM a, NUM p) //the real algorithm is in this function 
{
    //Phase 1
    NUM u = p;
    NUM v = a;
    NUM r = 0;
    NUM s = 1;   //init
    int cu = 0;
    int cv = 0;  //counters of left shifts
    NUM Rmu = 1; //2^cu
    NUM Rmv = 1; //2^cv
    int size = sizeOfTheBiggerNumber(u,v); // should be flexible by the larger number
    int i = 0;

     //counters
    int add = 0;
    int sub = 0;
    int shift = 0;
    int even = 0;
    int test = 0;
    int zero = 0;
    int neg = 0;
    int loop = 0;
    int fbr = 0;  //first branch
    int sbr = 0;  //second branch
    int tbr = 0;  //third branch
    int mod = 0;
        

    while (((u^Rmu) != 0) && ((u+Rmu) != 0) && ((v^Rmv) != 0) && ((v+Rmv) != 0))
    {   
        loop++;
        /*printf("u = %d, ", u); bin(u, size);
        printf("v = %d, ", v); bin(v, size);
        printf("r = %d, ", r); bin(r, size);
        printf("s = %d, ", s); bin(s, size);
        printf("_______________________________________________________________________________________________________\n");
        */

        if ((bit(u, size) == 0 && bit(u, size-1) == 0)|| ((bit(u, size) == 1 && bit(u, size-1) == 1) && (bits(u, size-2) == 1)))
        {
            fbr++; //entered the first branch
            u = (u<<1); shift++; //left shift is performed right away
            Rmu = (Rmu<<1); 
            cu++; //counter
            even++; //if s is even
            if (s%2 == 0) 
            {
                s = (s>>1); shift++;
            }
            else
            {
                s = s + p; add++; //first correction - we need to divide even number by two
                s = (s>>1); shift++;
            }
        }
        else if ((bit(v, size) == 0 && bit(v, size-1) == 0)|| ((bit(v, size) == 1 && bit(v, size-1) == 1) && (bits(v, size-2) == 1)))
        {
            sbr++; //entered the second branch
            v = (v<<1); shift++;
            Rmv = (Rmv<<1); 
            cv++;
            even++;
            if (r%2 == 0)
            {
                r = (r>>1); shift++;
            }
            else
            {
                r = r + p; add++;
                r = (r>>1); shift++;
            }
        }
        else
        {
            tbr++; //entered the third branch
            NUM oper; //0 is minus, 1 is plus
            if (bit(u, size) == bit(v, size))//check if the signs are the same
            {
                oper = 0; //minus
                sub++;sub++; //two subtractions will happen
            }
            else
            {
                oper = 1; //plus
                add++;add++; //two additions will happen
            }         
            //printf("%d\n", oper);
            //printf("u = %d, ", u); bin(u, size);
            //printf("v = %d, ", v); bin(v, size);
            if (cu <= cv)
            {
                u = (oper == 0) ? (u - v) : (u + v);
                r = (oper == 0) ? (r - s) : (r + s);
                sub++sub++; neg++; //comparison
                //if (r > p) { r = r - p; sub++; } 
                if ((r > p) || (r < -p))   
                {
                    //printf("r = %d, ", r); bin(r, size);
                    r = r % p;
                    mod++;
                    //printf("r = %d, ", r); bin(r, size);
                }
            }
            else
            {
                v = (oper == 0) ? (v - u) : (v + u);
                s = (oper == 0) ? (s - r) : (s + r);
                sub++sub++; neg++; //comparison
                //if (s > p) { s = s - p; sub++;} 
                if ((s > p) || (s < -p))   
                {
                    //printf("s = %d, ", s); bin(s, size);
                    s = s % p;
                    mod++;
                    //printf("s = %d, ", s); bin(s, size);
                }
            }
        }   
    }

    if (((v^Rmv) == 0) || ((v+Rmv) == 0))
    {
        r = s;
        NUM vnShifted = (v>>(size-2)); //the value is (0, 0, ..., vn)
        NUM vnCorrect = (vnShifted<<(size - 2)); //the value is (vn, 0, 0, ..., 0)
        NUM unShifted = (u>>(size - 2)); //the value is (0, 0, ..., un)
        NUM unCorrect = (unShifted<<(size - 2)); //the value is (un, 0, 0, ..., 0)
        u = u^unCorrect^vnCorrect; //the result is un := vn
        //u = (bit(v, size)<<(size-1)) + bits(u, size-1);
        cv = cu;
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
        /*printf("Result Phase 1\n");
        printf("u = %d, ", u); bin(u, size);
        printf("v = %d, ", v); bin(v, size);
        printf("r = %d, ", r); bin(r, size);
        printf("s = %d, ", s); bin(s, size);
        printf("_______________________________________________________________________________________________________\n");
        */
    
    for (size_t i = 1; i < (cv + 1); i++)
    {
        r = (r<<1); shift++;
        test++;
        if (r >= p)
        {
            r = (r - p); 
            sub++;
        }
        //printf("r = %d, ", r); bin(r, size);
        zero;
        if (r < 0)
        {
            r = r + p; 
            add++;
        }
        //printf("r = %d, ", r); bin(r, size);
        //printf("_______________________________________________________________________________________________________\n");
        
    } 
    
    
    FILE *fp;
    fp = fopen("a6.txt", "a");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, r, p, (r*a)%p, add ,sub, shift, even, neg, loop, fbr, sbr, tbr, cu, cv);
    fclose(fp);
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
    
    TW( a, p);
    
    return 0;
}
