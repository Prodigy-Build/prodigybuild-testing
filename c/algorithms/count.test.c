#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

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
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

void test_count()
{
    // Test case 1
    printf("Test case 1: count(5)\n");
    count(5);
    
    // Test case 2
    printf("Test case 2: count(25)\n");
    count(25);
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);

    test_count();
    
    return 0;
}