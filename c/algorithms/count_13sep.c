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

    return i;
}

void testCount() {
    assert(count(10) == 10);
    assert(count(21) == 21);
    assert(count(0) == 0);
    printf("All tests passed.\n");
}

int main()
{
    testCount();

    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    return count(num);
}