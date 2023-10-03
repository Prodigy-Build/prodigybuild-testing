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

void test_count() {
    count(5);
    count(10);
    count(25);
    count(0);
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