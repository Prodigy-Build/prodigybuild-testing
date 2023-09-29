#include <stdio.h>
#include <assert.h>

int main()
{
    long a;
    long b;
    
    for(a = 0, b = 1; b > a; b++)
    {
        a++;
        printf("%ld \n %ld", &a, &b);
    }
    
    if(b == sizeof(long))
    {
        exit(1);
    }
    
    // Unit test cases
    assert(a == 1);
    assert(b == 2);
    assert(sizeof(a) == sizeof(long));
    assert(sizeof(b) == sizeof(long));
    
    return 0;
}