#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n)
{
    long a = 0;
    long b = 1;
    
    for(int i = 0; i < n; i++)
    {
        printf("%ld\n%ld\n", a, b);
        long temp = a + b;
        a = b;
        b = temp;
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    fibonacci(n);
    
    return 0;
}