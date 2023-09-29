#include <stdio.h>
#include <stdbool.h>

bool isEven(int num);

void test_isEven()
{
    printf("Testing isEven function\n");
    
    // Test case 1: even number
    int num1 = 4;
    if (isEven(num1))
        printf("Test case 1 passed\n");
    else
        printf("Test case 1 failed\n");
    
    // Test case 2: odd number
    int num2 = 7;
    if (!isEven(num2))
        printf("Test case 2 passed\n");
    else
        printf("Test case 2 failed\n");
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (isEven(num))
        printf("Even");
    else
        printf("Odd");
    
    return 0;
}

bool isEven(int num)
{
    return (num % 2) == 0;
}