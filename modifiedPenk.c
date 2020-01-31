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

char *binbin(int n)     //display binary
{
    static char bin[9];
    int x;
    for( x = 0; x < 8; x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[x] = ' ';
    return(bin);
}

void binarySandBox (int a, int p) // this is a function with a fex binary operations, just for test and inspiration. to be erased.
{
    printf("Integer a = %d \n", a);
    printf("Prime p = %d \n", p);
    
    printf("%d is binary %s\n", a, binbin(a));
    printf("%d is binary %s\n", p, binbin(p));

    printf("a&p = %d %s\n", a & p, binbin(a & p)); 
  
    // The result is 00001101 
    printf("a|p = %d %s\n", (a | p), binbin(a | p)); 
  
    // The result is 00001100 
    printf("a^p = %d %s\n", a ^ p, binbin(a^p)); 
  
    // The result is 11111010 
    printf("~a = %hu %s\n", ~a, binbin(~a)); 
  
    // The result is 00010010 
    printf("p<<1 = %d %s\n", p << 1, binbin(p<<1)); 
  
    // The result is 00000100 
    printf("p>>1 = %d %s\n", p >> 1, binbin(p>>1)); 

    return;
}


int modifiedPenk(int a, int p, int *result, int *halvings) //the real algorithm is in this function
{
    int u = p; //init - line 1
    int v = a; 
    int r = 0;
    int s = 1;
    int k = 0; //init counter - line 2
    int x = 0; //difference?
    while (v > 0) //while loop - line 3
    {
        if (u % 2 == 0) //is this really the way to test the parity? what about checking the last bit? Does C do it like this?
        {
            if (r % 2 == 0) //r is even - line 5
            {
                u = u>>1; //halving - right shift
                r = r>>1; 
                k++; //line 6
                printf("u = %d r = %d k = %d \n", u, r, k);
            }
            else
            {
                u = u>>1; //halving - right shift
                r = (r + p)>>1; 
                k++; //line 8
                printf("u = %d r = %d k = %d \n", u, r, k);
            }
        }
        else if (v % 2 == 0)
        {
            if (s % 2 == 0)
            {
                v = v>>1; //halving - right shift
                s = s>>1; 
                k++; //line 11
                printf("v = %d s = %d k = %d \n", v, s, k);
            }
            else
            {
                v = v>>1; //halving - right shift
                s = (s + p)>>1; 
                k++; //line 11
                printf("v = %d s = %d k = %d \n", v, s, k);
            }
            
        }
        else
        {
            x = (u - v); //line 14
            if (x > 0)  
            {
                u = x;
                r = r - s;
                if (r < 0)
                {
                    r = r + p;
                }
            }
            else
            {
                v = -x;
                s = s - r;
                if (s < 0)
                {
                    s = s + p; //line 22
                }
                
            }
            
        }    
    }
    if (r > p)
    {
        r = r - p; //line 24
    }
    if (r < 0)
    {
        r = r + p;
    }
    *result = r;
    *halvings = k;//line 27
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
    
    //binarySandBox(a, p); //just playing with binary stuff, to be erased

    modifiedPenk(a, p, &result, &halvings); //THEREALALGORITHM
    printf("Result r = %d, k = %d \n", result, halvings);

    
    return 0;
}