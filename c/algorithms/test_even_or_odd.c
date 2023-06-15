

#include <stdio.h>
#include <assert.h>

int even_or_odd(long num)
{
    int rem = num % 2;
    if(rem == 0)
        return 0;
    else
        return 1;
}

void test_even_or_odd()
{
    assert(even_or_odd(2) == 0);
    assert(even_or_odd(3) == 1);
    assert(even_or_odd(4) == 0);
    assert(even_or_odd(5) == 1);
    assert(even_or_odd(6) == 0);
    assert(even_or_odd(7) == 1);
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if(rem == 0)
    printf("Even");
    else
    printf("Odd");
    test_even_or_odd();
    return 0;
}