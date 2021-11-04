#ifndef BASE
#define BASE
#include "basicFuncs.h"
#endif

int isPrime(int num){
    for (int i = 2; i <= num/2; i++)
    {
        if (num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isStrong(int num){
    int sum = 0;
    int count = countDigit(num);

    for (int i = 0; i < count; i++)
    {
        int digit = num/power(10,i)%10;
        sum = sum + factorial(digit);
    }

    if (sum == num)
    {
        return 1;
    }
    else{
        return 0;
    }    
}

