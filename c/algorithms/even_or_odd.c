#include <stdio.h>
#include <assert.h>

void test_even_or_odd()
{
    long num;
    
    num = 2;
    assert(even_or_odd(num) == 0);
    
    num = 7;
    assert(even_or_odd(num) == 1);
    
    num = -4;
    assert(even_or_odd(num) == 0);
    
    num = -9;
    assert(even_or_odd(num) == 1);
    
    printf("All test cases pass\n");
}

int even_or_odd(long num)
{
    int rem = num % 2;
    
    if(rem == 0)
        return 0;
    else
        return 1;
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (even_or_odd(num) == 0)
        printf("Even");
    else
        printf("Odd");
        
    test_even_or_odd();
    
    return 0;
}