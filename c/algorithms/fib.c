#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to calculate Fibonacci series up to n
void fibonacci(int n)
{
    long a = 0;
    long b = 1;
    
    for (int i = 0; i < n; i++)
    {
        printf("%ld\n%ld\n", a, b);
        
        long temp = a + b;
        a = b;
        b = temp;
    }
}

// Function to check if b is equal to the size of long
bool isBEqualToLongSize()
{
    long b = 1;
    
    return b == sizeof(long);
}

// Test case for the fibonacci function
void testFibonacci()
{
    // Test case 1
    printf("Test Case 1:\n");
    printf("Expected Output: 0\n1\n1\n2\n3\n");
    printf("Actual Output: ");
    fibonacci(5);
    printf("\n");
    
    // Test case 2
    printf("Test Case 2:\n");
    printf("Expected Output: 0\n1\n1\n2\n3\n5\n8\n");
    printf("Actual Output: ");
    fibonacci(7);
    printf("\n");
}

// Test case for the isBEqualToLongSize function
void testIsBEqualToLongSize()
{
    // Test case 1
    bool result = isBEqualToLongSize();
    printf("Test Case 1:\n");
    printf("Expected Output: false\n");
    printf("Actual Output: %s\n", result ? "true" : "false");
    
    // Test case 2
    long b = sizeof(long);
    printf("Test Case 2:\n");
    printf("Expected Output: true\n");
    printf("Actual Output: %s\n", b == sizeof(long) ? "true" : "false");
}

int main()
{
    // Run the test cases
    testFibonacci();
    testIsBEqualToLongSize();
    
    return 0;
}