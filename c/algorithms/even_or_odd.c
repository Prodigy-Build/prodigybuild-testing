#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number: ");
    scanf("%ld", &num);
    
    int rem = num % 2;
    
    if (rem == 0) {
        printf("Even");
    } else {
        printf("Odd");
    }
    
    return 0;
}