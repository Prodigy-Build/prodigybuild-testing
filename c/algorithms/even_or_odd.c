#include <stdio.h>

int even_or_odd(long num) {
    int rem = num % 2;
    
    if (rem == 0)
        printf("Even");
    else
        printf("Odd");
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    even_or_odd(num);
    
    return 0;
}