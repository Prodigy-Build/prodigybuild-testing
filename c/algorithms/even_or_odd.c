#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    // Check if number is divisible by 2
    if (num % 2 == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }

    return 0;
}