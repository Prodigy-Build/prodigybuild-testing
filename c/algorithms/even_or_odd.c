#include <stdio.h>
#include <assert.h>

int even_or_odd(long num)
{
    return num % 2 == 0;
}

void test_even_or_odd() 
{
    assert(even_or_odd(2) == 1);
    assert(even_or_odd(3) == 0);
    assert(even_or_odd(0) == 1);
    assert(even_or_odd(-2) == 1);
    assert(even_or_odd(-3) == 0);
}

int main()
{
    test_even_or_odd();

    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if(even_or_odd(num))
        printf("Even");
    else
        printf("Odd");
    
    return 0;
}