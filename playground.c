#include <stdio.h>
#include<stdlib.h>


// variables and data types
unsigned int a, p; //from input


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
    //printf("p<<1 = %d %s\n", p << 1, binbin(p<<1)); 
    printf("p<<2 = %d %s\n", p << 2, binbin(p<<2)); 
  
    // The result is 00000100 
    //printf("p>>1 = %d %s\n", p >> 1, binbin(p>>1)); 
    printf("p>>2 = %d %s\n", p >> 2, binbin(p>>2));

    printf("bez prvnich dvou bitu = %s\n", binbin((p<<2)>>2));

    return;
}




int main(int argc, char* argv[])
{
    
    a = 0b1;
    p = 0b10101010;
    binarySandBox(a, p); //just playing with binary stuff, to be erased

  

    
    return 0;
}