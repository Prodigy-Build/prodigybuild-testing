#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a;
    long b;
    
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld\n", a, b); // Added newline character
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
    
    return 0; // Added return statement
}