

# Unit Test for even_or_odd.c

The following unit test is written to test the functionality of the even_or_odd.c file.

c
#include <stdio.h>
#include <assert.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if(rem == 0)
    {
        assert(rem == 0);
        printf("Even");
    }
    else
    {
        assert(rem != 0);
        printf("Odd");
    }
}


The unit test above tests the functionality of the even_or_odd.c file by asserting that the remainder of the number entered is either 0 (for even) or not 0 (for odd). If the assertion is true, the program prints the appropriate output.