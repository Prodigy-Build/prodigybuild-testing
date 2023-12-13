#include <stdio.h>
#include <stdlib.h>

void fibonacciSequence()
{
    long a = 0;
    long b = 1;
    
    while (a < b)
    {
        printf("%ld\n%ld\n", a, b);
        long temp = a;
        a = b;
        b = a + temp;
    }
    
    if (b == sizeof(long))
    {
        exit(1);
    }
}

int main()
{
    fibonacciSequence();
    return 0;
}