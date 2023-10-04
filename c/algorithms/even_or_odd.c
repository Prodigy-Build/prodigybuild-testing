#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function prototype
char* evenOrOdd(long num);

// Test cases
void test_evenOrOdd() {
    // Test case 1: Even number
    long num1 = 4;
    char* result1 = evenOrOdd(num1);
    assert(strcmp(result1, "Even") == 0);

    // Test case 2: Odd number
    long num2 = 7;
    char* result2 = evenOrOdd(num2);
    assert(strcmp(result2, "Odd") == 0);

    // Test case 3: Negative even number
    long num3 = -10;
    char* result3 = evenOrOdd(num3);
    assert(strcmp(result3, "Even") == 0);

    // Test case 4: Negative odd number
    long num4 = -15;
    char* result4 = evenOrOdd(num4);
    assert(strcmp(result4, "Odd") == 0);
}

int main() {
    // Run the test cases
    test_evenOrOdd();
    return 0;
}

// Function to determine if a number is even or odd
char* evenOrOdd(long num) {
    int rem = labs(num) % 2;
    if(rem == 0)
        return "Even";
    else
        return "Odd";
}