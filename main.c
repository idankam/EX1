#include <stdio.h>
#include "NumClass.h"

int main(){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    int max = num2, min = num1;
    if (num1>num2)
    {
        max = num1;
        min = num2;
    }
        
    printf("The Armstrong numbers are:");
    for(int i = min; i<=max; i++){
        if(isArmstrong(i)){ printf(" %d", i); }
    }
    printf("\nThe Palindromes are:");
    for(int i = min; i<=max; i++){
        if(isPalindrome(i)){ printf(" %d", i); }
    }
    printf("\nThe Prime numbers are:");
    for(int i = min; i<=max; i++){
        if(isPrime(i)){ printf(" %d", i); }
    }
    printf("\nThe Strong numbers are:");
    for(int i = min; i<=max; i++){
        if(isStrong(i)){ printf(" %d", i); }
    }
    printf("\n");
}