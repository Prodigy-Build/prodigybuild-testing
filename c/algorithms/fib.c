#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while (b > a)
    {
        a += b;
        printf("%ld \n %ld\n", a, b);
        b += a;
        printf("%ld \n %ld\n", a, b);
    }
    
    if (b == sizeof(long))
    {
        exit(1);
    }
}