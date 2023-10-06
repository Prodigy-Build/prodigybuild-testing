#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate the nth Fibonacci number
long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        long a = 0;
        long b = 1;
        long c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

// Unit test cases
int main() {
    // Test Case 1
    int n1 = 0;
    long expected1 = 0;
    long result1 = fibonacci(n1);
    if (result1 == expected1) {
        printf("Test Case 1 Passed\n");
    } else {
        printf("Test Case 1 Failed\n");
    }

    // Test Case 2
    int n2 = 1;
    long expected2 = 1;
    long result2 = fibonacci(n2);
    if (result2 == expected2) {
        printf("Test Case 2 Passed\n");
    } else {
        printf("Test Case 2 Failed\n");
    }

    // Test Case 3
    int n3 = 5;
    long expected3 = 5;
    long result3 = fibonacci(n3);
    if (result3 == expected3) {
        printf("Test Case 3 Passed\n");
    } else {
        printf("Test Case 3 Failed\n");
    }

    // Test Case 4
    int n4 = 10;
    long expected4 = 55;
    long result4 = fibonacci(n4);
    if (result4 == expected4) {
        printf("Test Case 4 Passed\n");
    } else {
        printf("Test Case 4 Failed\n");
    }

    return 0;
}