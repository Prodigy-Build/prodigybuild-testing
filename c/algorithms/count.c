#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num);

void test_count()
{
    // Test case 1
    int num1 = 5;
    count(num1);
    
    // Test case 2
    int num2 = 10;
    count(num2);
    
    // Test case 3
    int num3 = 25;
    count(num3);
}

int main()
{
    test_count();
    return 0;
}

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}