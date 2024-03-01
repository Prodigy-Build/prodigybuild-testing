#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
long fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        long a = 0;
        long b = 1;
        long c;
        
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        
        return b;
    }
}

// Unit test for the fibonacci function
void test_fibonacci()
{
    // Test case 1: n = 0
    int n = 0;
    long expected = 0;
    long result = fibonacci(n);
    if (result == expected)
    {
        printf("Test case 1 passed\n");
    }
    else
    {
        printf("Test case 1 failed\n");
    }
    
    // Test case 2: n = 1
    n = 1;
    expected = 1;
    result = fibonacci(n);
    if (result == expected)
    {
        printf("Test case 2 passed\n");
    }
    else
    {
        printf("Test case 2 failed\n");
    }
    
    // Test case 3: n = 5
    n = 5;
    expected = 5;
    result = fibonacci(n);
    if (result == expected)
    {
        printf("Test case 3 passed\n");
    }
    else
    {
        printf("Test case 3 failed\n");
    }
    
    // Test case 4: n = 10
    n = 10;
    expected = 55;
    result = fibonacci(n);
    if (result == expected)
    {
        printf("Test case 4 passed\n");
    }
    else
    {
        printf("Test case 4 failed\n");
    }
}

int main()
{
    test_fibonacci();
    
    return 0;
}