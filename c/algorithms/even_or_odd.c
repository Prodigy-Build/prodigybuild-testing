#include <stdio.h>
#include <stdlib.h>

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
}

// Unit test cases
void test_even_or_odd() {
    long num1 = 4;
    long num2 = 7;
    long num3 = -10;
    
    int rem1 = num1 % 2;
    int rem2 = num2 % 2;
    int rem3 = num3 % 2;
    
    if(rem1 == 0)
    printf("Even");
    else
    printf("Odd");
    
    if(rem2 == 0)
    printf("Even");
    else
    printf("Odd");
    
    if(rem3 == 0)
    printf("Even");
    else
    printf("Odd");
}