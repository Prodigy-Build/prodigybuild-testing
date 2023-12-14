#include <stdio.h>

int main()
{
    long a;
    long b;
    
    // Initialize a and b
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", &a, &b);
    }
    
    // Check if b is equal to the size of long
    if(b == sizeof(long))
    {
        exit(1);
    }
}