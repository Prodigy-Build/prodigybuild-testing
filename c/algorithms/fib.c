#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 0;
    long b = 1;

    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b);
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
}

// Unit test cases
void test_algorithm()
{
    // Test case 1
    long a = 0;
    long b = 1;
    
    // Expected output: 0 \n 1
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b);
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
    
    // Test case 2
    a = 0;
    b = 1;
    
    // Expected output: 0 \n 1
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", a, b);
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
}