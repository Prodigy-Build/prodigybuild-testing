#include <stdio.h>

int main()
{
    long num;

    printf("Enter a number\n");
    scanf("%ld", &num);
    
    // Check if the number is even or odd
    if (num % 2 == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }

    return 0;
}