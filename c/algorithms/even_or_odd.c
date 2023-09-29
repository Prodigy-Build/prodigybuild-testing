#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is even or odd
bool isEven(int num) {
    return num % 2 == 0;
}

// Unit test cases
int main() {
    // Test case 1: Even number
    int num1 = 4;
    if (isEven(num1))
        printf("Test case 1 passed\n");
    else
        printf("Test case 1 failed\n");

    // Test case 2: Odd number
    int num2 = 3;
    if (!isEven(num2))
        printf("Test case 2 passed\n");
    else
        printf("Test case 2 failed\n");

    // Test case 3: Zero
    int num3 = 0;
    if (isEven(num3))
        printf("Test case 3 passed\n");
    else
        printf("Test case 3 failed\n");

    return 0;
}