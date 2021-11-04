#include "basicFuncs.h"

int isArmstrong(int x){
    int number = x;
    int sum = 0;
    int count = countDigit(number);

    for (int i = 0; i < count; i++)
    {
        int p = power(10,i);
        int digit = (number/p) %10;
        sum = sum + power(digit,count);
    }

    if (sum == number)
    {
        return 1;
    }
    else{
        return 0;
    }    
}



int isPalindrome(int num){
    int last = countDigit(num)-1;
    int first = 0;
    while (last > first)
    {
        int dig1 = num/power(10,last)%10;
        int dig2 = num/power(10,first)%10;
        if (dig1 != dig2)
        {
            return 0;
        }
        last--;
        first++;
    }
    return 1;
}
