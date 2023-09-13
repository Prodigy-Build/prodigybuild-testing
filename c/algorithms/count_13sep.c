#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) 
{
    int count = 0;
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++) {
            printf("\n%d, \n", i);
            ++count;
        }
            
        if(i == num)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++) {
            printf("%d", i);
            ++count;
        }
            
        if(i == num)
            printf("]");
    }
    return count;
}

void testCount() {
    assert(count(30) == 30);
    assert(count(10) == 10);
    assert(count(0) == 0);
    assert(count(-1) == 0);
    printf("All test cases passed\n");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    printf("%d\n", count(num));
    testCount();
    return 0;
}