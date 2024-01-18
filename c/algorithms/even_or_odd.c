#include <stdio.h>

// Function to check if a number is even or odd
int isEvenOrOdd(long num)
{
    return num % 2 == 0;
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    // Using the isEvenOrOdd function to print if the number is even or odd
    if(isEvenOrOdd(num))
        printf("Even");
    else
        printf("Odd");

    return 0;
}