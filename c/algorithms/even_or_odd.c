#include <stdio.h>

// Function to determine if a number is even or odd
void determineEvenOrOdd(long num) {
    int rem = num % 2;

    if(rem == 0)
        printf("Even");
    else
        printf("Odd");
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    determineEvenOrOdd(num);

    return 0;
}