#include <stdio.h>
#include<stdlib.h>
#include <math.h> 

typedef signed short NUM; //the basic data type for all the operations / has to be signed to function!

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
    int i = 0;

        //to be erased, just text checkers
        /* printf("u = %d, ", u); bin(u);
        printf("v = %d, ", v); bin(v);
        printf("r = %d, ", r); bin(r);
        printf("s = %d, ", s); bin(s);
        printf("cu = %d, 2^cu = %d ", cu, power(2, cu)); bin(cu);
        printf("cv = %d, 2^cv = %d ", cv, power(2, cv)); bin(cv); */


    while (u != power(2, cu) && u != -(power(2, cu)) && v != power(2, cv) && v != -(power(2, cv))) 
  
    //while (i < 11)
    {   
        i++; 
        NUM mask = 0b11 << (size - 2);
        // printf("_______________________________________________________________________________________________________\n");
        // printf("%d\n",i);
        
        if (((mask&u) == 0) || (((mask&u) == mask) && ((u<<2) != 0)))
        {
            //printf("line 5 - uvnitr prvniho if \n");
            if (cu >= cv)   
            {
                u = (u<<1);
                r = (r<<1);
                cu++;
            }
            else
            {
                u = (u<<1);
                s = (s>>1);
                cu++;
            }
        }
        else if (((mask&v) == 0) || (((mask&v) == mask) && (v<<2) != 0))
        {
            //printf("line 10 - uvnitr else if \n");
            if (cv >= cu)   
            {
                v = (v<<1);
                s = (s<<1);
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
            //printf("line 15 - else vetev \n");
            maskU = (u>>(size-1));
            maskV = (v>>(size-1));
            /*bin(maskU);
            bin(maskV); */
            NUM oper; //0 is minus, 1 is plus
            if (maskV == maskU ) //check if the signs are the same
            {
                oper = 0; //minus
            }
            else
            {
                oper = 1; //plus
            }
            //printf("oper = %d\n", oper);
            if (cu <= cv)
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
        /* printf("u = %d, ", u); bin(u);
        printf("v = %d, ", v); bin(v);
        printf("r = %d, ", r); bin(r);
        printf("s = %d, ", s); bin(s);
        printf("cu = %d, 2^cu = %d ", cu, power(2, cu)); bin(cu);
        printf("cv = %d, 2^cv = %d ", cv, power(2, cv)); bin(cv);
        printf("mask&u ");bin(mask&u);
        printf("mask&v ");bin(mask&v); */
    }


    if (v == power(2,cv) || v == -power(2,cv))
    {
        r = s;
        NUM vnShifted = (v>>(size-2)); //the value is (0, 0, ..., vn)
        NUM vnCorrect = (vnShifted<<(size - 2)); //the value is (vn, 0, 0, ..., 0)
        NUM unShifted = (u>>(size - 2)); //the value is (0, 0, ..., un)
        NUM unCorrect = (unShifted<<(size - 2)); //the value is (un, 0, 0, ..., 0)
        u = u^unCorrect^vnCorrect; //the result is un := vn
        //printf("line 24");
    }

    if (u < 0)
    {
        if (r < 0)
        {
            r = -r;
            //printf("line 27");
        }
        else
        {
            r = p - r;
            //printf("line 29");
        }  
    }
    
    if (r < 0)
    {
        r = r + p;
        //printf("line 31");
    }
    
    printf("%d %d %d\n", a, r, p);
    //bin(r);
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
