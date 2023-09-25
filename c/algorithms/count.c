#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num);

void test_count()
{
    assert(count(0) == 0);
    assert(count(1) == 1);
    assert(count(10) == 10);
    assert(count(15) == 15);
    assert(count(20) == 20);
    assert(count(21) == 21);
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
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
    
    return num;
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