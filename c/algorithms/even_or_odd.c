

#include <stdio.h>
#include <assert.h>

int even_or_odd(long num);

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
}

int even_or_odd(long num)
{
    int rem = num % 2;
    return rem;
}

// Unit Test Cases
void test_even_or_odd()
{
    assert(even_or_odd(2) == 0);
    assert(even_or_odd(3) == 1);
    assert(even_or_odd(4) == 0);
    assert(even_or_odd(5) == 1);
    assert(even_or_odd(6) == 0);
    assert(even_or_odd(7) == 1);
    assert(even_or_odd(8) == 0);
    assert(even_or_odd(9) == 1);
}