#include <stdio.h>
#include<stdlib.h>

// variables and data types
unsigned int a, p; //from input

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

void binarySandBox (int a, int p)
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


int modifiedPenk(int a, int p)
{
    int u = p;
    int v = a;
    int r = 0;
    int s = 1;
    int k = 0;
    while (v > 0)
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
    
    //binarySandBox(a, p);

    modifiedPenk(a, p);

    
    return 0;
}