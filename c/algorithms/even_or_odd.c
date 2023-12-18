// Include necessary libraries
#include <stdio.h>
#include <stdbool.h>

// Define function to check if a number is even or odd
bool isEven(int number) { 
    return number % 2 == 0;
}

// Unit test cases
int main() {
    // Test case 1: Even number
    int num1 = 8;
    printf("Number: %d\n", num1);
    if (isEven(num1)) {
        printf("Result: Even\n");
    } else {
        printf("Result: Odd\n");
    }

    // Test case 2: Odd number
    int num2 = 15;
    printf("Number: %d\n", num2);
    if (isEven(num2)) {
        printf("Result: Even\n");
    } else {
        printf("Result: Odd\n");
    }

    return 0;
}