#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    int i;
    for(i = 0; i < num; i++)
        printf("%d", i);
        
    if(i == num)
        printf("]");
}

void test_count()
{
    printf("Testing count function\n");
    
    // Test case 1
    int num1 = 5;
    printf("Test case 1: num = %d\n", num1);
    count(num1);
    printf("\nExpected output: 01234]\n");
    printf("\n");
    
    // Test case 2
    int num2 = 10;
    printf("Test case 2: num = %d\n", num2);
    count(num2);
    printf("\nExpected output: 0123456789]\n");
    printf("\n");
    
    // Test case 3
    int num3 = 20;
    printf("Test case 3: num = %d\n", num3);
    count(num3);
    printf("\nExpected output: 012345678910111213141516171819]\n");
    printf("\n");
    
    // Test case 4
    int num4 = 25;
    printf("Test case 4: num = %d\n", num4);
    count(num4);
    printf("\nExpected output: 0123456789101112131415161718192021222324]\n");
    printf("\n");
}

int main()
{
    test_count();
    return 0;
}