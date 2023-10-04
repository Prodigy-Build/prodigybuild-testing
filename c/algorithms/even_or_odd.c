#include <stdio.h>

int even_or_odd(long num) {
    int rem = num % 2;

    if (rem == 0)
        return 0; // Even
    else
        return 1; // Odd
}

void test_even_or_odd() {
    // Test cases
    printf("%s\n", even_or_odd(0) == 0 ? "Test Passed" : "Test Failed");
    printf("%s\n", even_or_odd(4) == 0 ? "Test Passed" : "Test Failed");
    printf("%s\n", even_or_odd(7) == 1 ? "Test Passed" : "Test Failed");
    printf("%s\n", even_or_odd(10) == 0 ? "Test Passed" : "Test Failed");
    printf("%s\n", even_or_odd(-5) == 1 ? "Test Passed" : "Test Failed");
}

int main() {
    // Run the test cases
    test_even_or_odd();
    return 0;
}