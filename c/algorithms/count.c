#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

int count(int num);

void test_count()
{
    assert(count(10) == 10);
    assert(count(5) == 5);
    assert(count(25) == 25);
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