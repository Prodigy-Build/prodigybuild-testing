#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int isEven = (num % 2 == 0);
    
    if(isEven)
        printf("Even");
    else
        printf("Odd");
    return 0;
}