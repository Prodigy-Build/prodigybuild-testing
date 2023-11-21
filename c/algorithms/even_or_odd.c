#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOdd(long num) {
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
    
    // Call the function to check if the number is even or odd
    checkEvenOdd(num);
    
    return 0;
}