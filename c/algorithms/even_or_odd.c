#include <stdio.h>

void checkEvenOrOdd(long num){
    int rem = num % 2;
    
    if(rem == 0)
    printf("Even");
    else
    printf("Odd");
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    checkEvenOrOdd(num);

    return 0;
}