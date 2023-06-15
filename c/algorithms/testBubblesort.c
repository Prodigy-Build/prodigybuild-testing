

#include <stdio.h>
#include <assert.h>

int even_or_odd(long num)
{
    int rem = num % 2;
    return rem;
}

void test_even_or_odd()
{
    assert(even_or_odd(2) == 0);
    assert(even_or_odd(3) == 1);
    printf("Even or odd test passed!\n");
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = even_or_odd(num);
    
    if(rem == 0)
    printf("Even");
    else
    printf("Odd");
    test_even_or_odd();
    return 0;
}