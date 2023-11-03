#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if(rem == 0)
        printf("Number is even");
    else
        printf("Number is odd");
}