#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    printf("[");
    int i;
    for(i = 0; i < num; i++)
    {
        if(num > 20)
            printf("\n%d, \n", i);
        else
            printf("%d", i);
    } 
    if(i == num)
        printf("]");
    return i;
}

void test_count() 
{
    assert(count(5) == 5);
    assert(count(30) == 30);
}

int main()
{
    test_count();
    printf("All tests passed\n");
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}