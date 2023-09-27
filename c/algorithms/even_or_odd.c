#include <stdio.h>

int isEvenOrOdd(int num) {
    int rem = num % 2;
    
    if (rem == 0)
        return 1;
    else
        return 0;
}

int main() {
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if (isEvenOrOdd(num))
        printf("Even");
    else
        printf("Odd");
        
    return 0;
}