#ifndef BASE
#define BASE
#include "basicFuncs.h"
#endif

int isArmHelp(int number, int count);
int reverse(int num);

int isArmstrong(int number){
    int count = countDigit(number);
    if (number == isArmHelp(number, count))
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isArmHelp(int number, int count){
    if(number<10){
        return power(number, count);
    }
    else{
        return (power(number%10, count) + isArmHelp(number/10, count));
    }
}

int isPalindrome(int num){
    //printf("%d\n", reverse(num));
    if (num == reverse(num))
    {
        return 1;
    }
    else{
        return 0;
    }
}

int reverse(int num)
{
    /* Find number of digits in num */
    int digits = countDigit(num);
    //printf("%d\n", digit);
    /* Recursion base condition */
    if(num == 0)
        return 0;
    //printf("%d\n", ((num%10 * power(10, digit)) + reverse(num/10)));
    return ((num%10 * power(10, digits-1)) + reverse(num/10));
}

