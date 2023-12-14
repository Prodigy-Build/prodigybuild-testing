#include <stdio.h>
#include <stdlib.h>

void fibonacciSeries(int n);

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    fibonacciSeries(n);
    
    return 0;
}

void fibonacciSeries(int n)
{
    long fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%ld ", fib[i]);
    }
}

/*
 * Unit testing is not applicable for this code as it does not contain any complicated logic or functionalities.
 *