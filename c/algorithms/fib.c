```c
#include <stdio.h>
#include <assert.h>

// Function to be tested
long fib(long n)
{
    long a = 0;
    long b = 1;
    
    for(long i = 0; i < n; i++)
    {
        long temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

// Our test
void test_fib() {
    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(10) == 55);
    printf("All tests passed.\n");
}

int main()
{
    test_fib();
    return 0;
}
```