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
    int shift = 0;
    int even = 0;
    int test = 0;
    int zero = 0;
    int neg = 0;
    int loop = 0;


    while (v > 0)
    {
        loop++; //while (v > 0)
        if (u % 2 == 0)
        {
            even++; //if (u % 2 == 0)
            u = u>>1;
            shift++;
            s = s<<1; //multiply by 2 - left shift, line 5
            shift++;
            k++;
        }
        else if (v % 2 == 0)
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            v = v>>1;
            shift++;
            r = r<<1;
            shift++;
            k++;
        }
        else //line 8
        {
            even++; //if (u % 2 == 0)
            even++; //if (v % 2 == 0)
            x = u - v;
            sub++;
            zero++; //if (x > 0)
            if (x > 0)
            {
                u = x>>1;
                shift++;
                r = r + s;
                add++;
                s = s<<1;
                shift++;
                k++;
            }
            else //line 12
            {
                v = -(x>>1);
                shift++;
                neg++;
                s = r + s;
                add++;
                r = r<<1;
                shift++;
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
    

    FILE *fp;
    fp = fopen("a2p1.txt", "a");
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d\n", a, r, p, shift, add, sub, test, zero, neg, loop, even, k);
    fclose(fp);

    //counters
    add = 0;
    sub = 0;
    shift = 0;
    even = 0;
    test = 0;
    zero = 0;
    neg = 0;
    loop = 0;

    for (int i = 0; i < k; i++) //k is the number of halvings from phase 1
    {
        loop++;
        even++;
        if (r % 2 == 0)
        {
            r = r>>1;
            shift++;
        }
        else
        {
            r = (r + p)>>1;
            add++;
            shift++;
        }                
    }
    //printf("Result r = %d\n", r);
    *result = r;
    *halvings = k<<1;

    FILE *fp2;
    fp2 = fopen("a2p2.txt", "a");
    fprintf(fp2, "%d %d %d %d %d %d %d %d %d %d %d %d\n", a, r, p, shift, add, sub, test, zero, neg, loop, even, k);
    fclose(fp2);

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
    //printf("%d %d %d\n", a, result, p);

    
    return 0;
}