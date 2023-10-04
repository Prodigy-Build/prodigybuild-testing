#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a;
    long b;
    
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

// Unit test cases:

#include <assert.h>

void test_fibonacci()
{
    long a;
    long b;
    
    printf("Test 1\n");
    a = 0;
    b = 1;
    for(int i = 0; i < 10; i++)
    {
        long temp = a;
        a = b;
        b = temp + b;
        printf("%ld\n", a);
    }
    assert(a == 55);
    assert(b == 89);
    
    printf("Test 2\n");
    a = 0;
    b = 1;
    for(int i = 0; i < 15; i++)
    {
        long temp = a;
        a = b;
        b = temp + b;
        printf("%ld\n", a);
    }
    assert(a == 610);
    assert(b == 987);
    
    // Add more test cases if needed
}

int main()
{
    test_fibonacci();
    return 0;
}