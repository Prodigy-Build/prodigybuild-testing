#include <stdio.h>

void displayEvenOrOdd(long num);

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    displayEvenOrOdd(num);
    return 0;
}

void displayEvenOrOdd(long num)
{
    int rem = num % 2;

    if(rem == 0)
        printf("Even");
    else
        printf("Odd");
}