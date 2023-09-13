#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
    
    return num;
}

void testCount()
{
    assert(count(5) == 5);
    assert(count(21) == 21);
    assert(count(100) == 100);
    assert(count(20) == 20);
}

int main()
{
    testCount();
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}