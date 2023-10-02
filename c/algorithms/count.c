#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num);

int main()
{
    // Unit test cases
    assert(count(0) == 0);
    assert(count(5) == 5);
    assert(count(20) == 20);
    assert(count(21) == 22);
    assert(count(-1) == 0);

    printf("All test cases pass\n");

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

    return num;
}