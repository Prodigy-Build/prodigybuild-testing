

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
    return 0;
}

void test_count()
{
    assert(count(5) == 0);
    assert(count(20) == 0);
    assert(count(25) == 0);
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

