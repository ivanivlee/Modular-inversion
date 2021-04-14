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
    //init
    int u = p;
    int v = a; 
    int r = 0;
    int s = 1;
    int k = 0; 
    int x = 0; //difference?

    //counters
    int add = 0;
    int sub = 0;
    int shift = 0;
    int even = 0;
    int test = 0;
    int zero = 0;
    int neg = 0;
    int loop = 0;
    
    while (v > 0) 
    {
        loop++; //while (v > 0)
        if (u % 2 == 0) //is this really the way to test the parity? what about checking the last bit? Does C do it like this?
        {
            even++; //if (u % 2 == 0)
            even++; //if (r % 2 == 0)
            if (r % 2 == 0) 
            {
                u = u>>1; 
                shift++;
                r = r>>1;
                shift++; 
                k++; 
            }
            else
            {
                u = u>>1; 
                shift++;
                r = (r + p)>>1; 
                shift++;
                add++;
                k++; 
            }
        }
        else if (v % 2 == 0)
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            even++; //if (s % 2 == 0)
            if (s % 2 == 0)
            {
                v = v>>1; 
                shift++;
                s = s>>1; 
                shift++;
                k++; //line 11
                //printf("v = %d s = %d k = %d \n", v, s, k);
            }
            else
            {
                v = v>>1; 
                shift++;
                s = (s + p)>>1; 
                shift++;
                add++;
                k++; //line 11
                //printf("v = %d s = %d k = %d \n", v, s, k);
            }
        }
        else
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            x = (u - v); 
            sub++; //x = (u - v); 
            zero++; // if (x > 0) 
            if (x > 0)  
            {
                u = x;
                r = r - s;
                sub++;
                zero++; //if (r < 0)
                if (r < 0)
                {
                    r = r + p;
                    add++;
                }
            }
            else
            {
                v = -x;
                neg++;
                s = s - r;
                sub++;
                zero++; //if (s < 0)
                if (s < 0)
                {
                    s = s + p; //line 22
                    add++;
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

    FILE *fp;
    fp = fopen("a1.txt", "a");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", a, r, p, shift, add, sub, test, zero, neg, loop, even, k);
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
    
    //binarySandBox(a, p); //just playing with binary stuff, to be erased

    modifiedPenk(a, p, &result, &halvings); //THEREALALGORITHM

    //printf("%d %d %d \n", a, result, p);
    return 0;
}