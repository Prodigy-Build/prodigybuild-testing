

#include <stdio.h>
#include <assert.h>

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

    // Unit Test
    assert(rem == 0);
    assert(rem != 0);
}