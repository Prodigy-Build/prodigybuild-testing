#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a;
    long b;
    
    // Generate Fibonacci sequence
    for(a = 0, b = 1; b > a; b++)
    {
        a = a + b;
        printf("%ld \n %ld", a, b);
    }
    
    // Check if the size of 'b' is equal to the size of 'long' type
    if(sizeof(b) == sizeof(long))
    {
        exit(1);
    }
}