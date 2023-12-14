#include <stdio.h>

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if (rem == 0) {
        printf("The number is Even\n");
    } else {
        printf("The number is Odd\n");
    }
    
    return 0;
}