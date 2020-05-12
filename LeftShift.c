#include <stdio.h>
#include<stdlib.h>
#include <math.h> 

typedef signed char NUM; //the basic data type for all the operations

// variables and data types
NUM a, p; //from input
NUM result, halvings; //to store the result and counter of halvings

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

NUM power(NUM base, NUM exp) //calculate base to the power of exp
{
    NUM i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int bin(NUM n) //display binary of SIGNED NUM
{ 
    NUM i;  
    int size = 8*(sizeof(NUM));
    (n < 0)? printf("1 "): printf("0 "); 
    for (i = 1 << (size - 2); i > 0; i = i / 2) // size - 1 if unsigned, size - 2 if signed
        (n & i)? printf("1 "): printf("0 ");  
    printf("\n");
    return 0;
} 

NUM leftshift(NUM a, NUM p) //the real algorithm is in this function 
{
    //Phase 1
    NUM u = p;
    NUM v = a;
    NUM r = 0;
    NUM s = 1;      //init
    NUM maskU, maskV;
    int cu = 0;
    int cv = 0;     //counters of left shifts
    int size = sizeof(NUM)*8;

    //while (u != power(2, cu) && u != -(power(2, cu)) && v != power(2, cv) && v != -(power(2, cv))) 
    int i = 0;
    while (i < 6)
    {   
        i++;
        NUM mask = 0b11 << (size - 2);
        printf("u = %d, ", u); bin(u);
        printf("v = %d, ", v); bin(v);
        printf("r = %d, ", r); bin(r);
        printf("cu = %d, ", cu); bin(cu);
        bin(mask&u);
        bin(mask);
        if (((mask&u) == 0) || (((mask&u) == 0b11) && ((u<<2) != 0)))
        {
            printf("line 5 - uvnitr prvniho if \n");
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
        else if (((mask&v) == 0) || (((mask&v) == 0b11) && (v<<2) != 0))
        {
            printf("line 10 - uvnitr else if \n");
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
            printf("line 15 - else vetev \n");
            maskU = (u>>(size-2));
            maskV = (v>>(size-2));
            bin(maskU);
            bin(maskV);
            NUM oper; //0 is minus, 1 is plus
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


    if (v == power(2,cv) || v == -power(2,cv))
    {
        r = s;
        NUM vnShifted = (v>>(size-2)); //the value is (0, 0, ..., vn)
        NUM vnCorrect = (vnShifted<<(size - 2)); //the value is (vn, 0, 0, ..., 0)
        NUM unShifted = (u>>(size - 2)); //the value is (0, 0, ..., un)
        NUM unCorrect = (unShifted<<(size - 2)); //the value is (un, 0, 0, ..., 0)
        u = u^unCorrect^vnCorrect; //the result is un := vn
    }

    if (u>>(size - 2) == 1)
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
    
    printf("The results:\nr = %d \n", r);
    bin(r);
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
    
    leftshift( a, p);
    
    
    
    return 0;
}