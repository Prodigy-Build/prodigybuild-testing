#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (num % 2 == 0)
        printf("Even");
    else
        printf("Odd");
}