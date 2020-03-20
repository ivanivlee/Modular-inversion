#include <stdio.h>
#include<stdlib.h>
#include <math.h> 

#define SIZE 8 //size of registers - for a moment, it is just 8!


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


char *binbin(int n)     //display binary
{
    static char bin[SIZE+1];
    int x;
    for( x = 0; x < SIZE; x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[x] = ' ';
    return(bin);
}

void binarySandBox (int a, int p) // this is a function with a fex binary operations, just for test and inspiration. to be erased.
{
    //printf("Integer a = %d \n", a);
    //printf("Prime p = %d \n", p);
    
    printf("%d is binary %s\n", a, binbin(a));
    printf("%d is binary %s\n", p, binbin(p));

    //printf("a&p = %d %s\n", a & p, binbin(a & p)); 
  
    // The result is 00001101 
    //printf("a|p = %d %s\n", (a | p), binbin(a | p)); 
  
    // The result is 00001100 
    //printf("a^p = %d %s\n", a ^ p, binbin(a^p)); 
  
    // The result is 11111010 
    //printf("~a = %hu %s\n", ~a, binbin(~a)); 
  
    // The result is 00010010 
    //printf("p<<1 = %d %s\n", p << 1, binbin(p<<1)); 
  
    // The result is 00000100 
    //printf("p>>1 = %d %s\n", p >> 1, binbin(p>>1)); 

    return;
}


int leftshift(int a, int p, int *result, int *halvings) //the real algorithm is in this function 
{
    //Phase 1
    unsigned u = p;
    unsigned v = a;
    unsigned r = 0;
    unsigned s = 1;      //init
    unsigned maskU, maskV;
    int cu = 0;
    int cv = 0;     //counters of left shifts

    printf("u,v\n");
    binarySandBox(u,v);
    printf("r,s\n");
    binarySandBox(r,s);



    while (u != (2^cu) && u != ~(2^cu) && v != (2^cv) && v != ~(2^cv)) // values with ~ are negative values, represented by complementary value
    {   
        maskU = (u>>(SIZE-2));
        maskV = (v>>(SIZE-2));
        printf("mask, %s", binbin(maskU));
        printf("mask, %s", binbin(maskV));
        if (maskU = 0 || (maskU = 0b11 && (u<<2) != 0))
        {
            if (cu >= cv)   
            {
                u = (u<<1);
                r = (r<<2);
                cu++;
            }
            else
            {
                u = (u<<1);
                s = (s>>1);
                cu++;
            }

        }
        else if (maskV = 0 || (maskV = 0b11 && (v<<2) != 0))
        {
            if (cv >= cu)   
            {
                v = (v<<1);
                s = (s<<2);
                cv++;
            }
            else
            {
                v = (v<<1);
                r = (r>>1);
                cv++;
            }
        }
        else
        {
            maskU = (u>>(SIZE-1));
            maskV = (v>>(SIZE-1));
            unsigned oper; //0 is minus, 1 is plus
            if (maskV == maskU )
            {
                oper = 0; //minus
            }
            else
            {
                oper = 1; //plus
            }
            if (cu <= cv)
            {
                u = (oper == 0) ? (u - v) : (u + v);
                r = (oper == 0) ? (r - s) : (r + s);
            }
            else
            {
                v = (oper == 0) ? (v - u) : (v + u);
                s = (oper == 0) ? (s - r) : (s + r);
            }

        
        }   
    }

    if (v == (2^cv) || v == ~(2^cv))
    {
        r = s;
        unsigned vnShifted = (v>>(SIZE-1)); //the value is (0, 0, ..., vn)
        unsigned vnCorrect = (vnShifted<<(SIZE -1)); //the value is (vn, 0, 0, ..., 0)
        unsigned unShifted = (u>>(SIZE-1)); //the value is (0, 0, ..., un)
        unsigned unCorrect = (unShifted<<(SIZE -1)); //the value is (un, 0, 0, ..., 0)
        u = u^unCorrect^vnCorrect; //the result is un := vn
    }

    if (u>>(SIZE-1) == 1)
    {
        if (r < 0)
        {
            r = ~r;
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
    
    printf("The results:\nr = %d %s, cu = %d, cv = %d", r, binbin(r), cu, cv);
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
    
    binarySandBox(a, p); //just playing with binary stuff, to be erased

    leftshift(a, p, &result, &halvings); //THEREALALGORITHM
    printf("Size of the registers is %d. \n", SIZE);

    
    return 0;
}