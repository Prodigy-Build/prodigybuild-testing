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
    return i;
}

// Unit test cases
void testCount(){
    assert(count(3) == 3);
    assert(count(12) == 12);
    assert(count(22) == 22);
    assert(count(40) == 40);
    assert(count(0) == 0);
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);

    // Run unit test cases
    testCount();

    return 0;
}