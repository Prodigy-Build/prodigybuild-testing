#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

long fibonacci(long n)
{
    if (n <= 1)
        return n;
    
    long a = 0;
    long b = 1;
    long fib = 0;
    
    for (long i = 2; i <= n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    
    return fib;
}

void test_fibonacci()
{
    // Test case 1: fibonacci(0)
    assert(fibonacci(0) == 0);
    
    // Test case 2: fibonacci(1)
    assert(fibonacci(1) == 1);
    
    // Test case 3: fibonacci(2)
    assert(fibonacci(2) == 1);
    
    // Test case 4: fibonacci(3)
    assert(fibonacci(3) == 2);
    
    // Test case 5: fibonacci(10)
    assert(fibonacci(10) == 55);
    
    // Test case 6: fibonacci(20)
    assert(fibonacci(20) == 6765);
}

int main()
{
    test_fibonacci();
    
    // Calculate and print Fibonacci sequence up to n = 20
    long n = 20;
    for (long i = 0; i <= n; i++)
    {
        printf("%ld ", fibonacci(i));
    }
    
    return 0;
}