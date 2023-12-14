#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while(b > a)
    {
        a++;
        printf("%ld \n %ld\n", a, b);
        b++;
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
}