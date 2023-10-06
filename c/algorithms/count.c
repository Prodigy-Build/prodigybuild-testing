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

void test_count()
{
    count(0);
    count(1);
    count(5);
    count(10);
    count(15);
    count(20);
    count(25);
}

int main()
{
    test_count();
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}