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
    count(10); // prints [0123456789]
    count(25); // prints [0, 1, 2, ..., 23, 24, \n]
    count(0); // prints []
    count(-1); // prints []
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}