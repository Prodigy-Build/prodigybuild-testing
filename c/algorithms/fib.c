#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// Unit test case for the Fibonacci algorithm
void test_fibonacci()
{
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 2);
    assert(fibonacci(4) == 3);
    assert(fibonacci(5) == 5);
    assert(fibonacci(6) == 8);
    assert(fibonacci(7) == 13);
    assert(fibonacci(8) == 21);
    assert(fibonacci(9) == 34);
}

// Function to calculate the nth Fibonacci number
long fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // Run the unit test case for Fibonacci
    test_fibonacci();
    
    return 0;
}