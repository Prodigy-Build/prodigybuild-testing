#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// Function to calculate Fibonacci number at given position
long fibonacci(int n) {
    long a = 0, b = 1, c;

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}

// Unit tests
void testFibonacci() {
    // Test case 1
    assert(fibonacci(0) == 0);

    // Test case 2
    assert(fibonacci(1) == 1);

    // Test case 3
    assert(fibonacci(2) == 1);

    // Test case 4
    assert(fibonacci(3) == 2);

    // Test case 5
    assert(fibonacci(4) == 3);

    // Test case 6
    assert(fibonacci(5) == 5);
}

int main()
{
    testFibonacci();

    return 0;
}