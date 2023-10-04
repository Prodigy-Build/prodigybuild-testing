#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ctest.h"

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

CTEST(count_test, test1) {
    ASSERT_EQUAL(5, count(5));
}

CTEST(count_test, test2) {
    ASSERT_EQUAL(10, count(10));
}

int main(int argc, const char *argv[]) {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}