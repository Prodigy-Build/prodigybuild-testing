#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if(rem == 0)
        printf("Even");
    else
        printf("Odd");
}

// This code is not testable as it only contains the main function and user input/output.