#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

void test_count()
{
    // Test case 1
    int num1 = 5;
    count(num1);
    
    // Test case 2
    int num2 = 25;
    count(num2);
    
    // Test case 3
    int num3 = 0;
    count(num3);
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

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    // Run tests
    test_count();
    
    return 0;
}