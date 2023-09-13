#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
        {
            printf("\n%d, \n", i);
        } 
            
        if(i == num + 1)
        {
            printf("]");
        }
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
        {
            printf("%d", i);
        }
            
        if(i == num)
        {
            printf("]");
        }
    }

    return num;
}

void test_count_function()
{
    assert(count(5) == 5);
    assert(count(20) == 20);
    assert(count(30) == 30);
    assert(count(50) == 50);
}

int main()
{
    test_count_function();

    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}