#include <stdio.h>
#include <assert.h>

void testIsEven()
{
    long num1 = 4;
    long num2 = -6;
    long num3 = 0;

    assert(isEven(num1) == 1);
    assert(isEven(num2) == 1);
    assert(isEven(num3) == 1);
}

void testIsOdd()
{
    long num1 = 3;
    long num2 = -5;
    long num3 = 7;

    assert(isOdd(num1) == 1);
    assert(isOdd(num2) == 1);
    assert(isOdd(num3) == 1);
}

int isEven(long num)
{
    return (num % 2 == 0);
}

int isOdd(long num)
{
    return (num % 2 != 0);
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    if(isEven(num))
        printf("Even");
    else
        printf("Odd");

    // Run unit tests
    testIsEven();
    testIsOdd();

    return 0;
}