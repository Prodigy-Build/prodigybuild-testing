#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
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
}

void count_test(int num, bool expected_result) {
    printf("Testing count(%d)\n", num);
    count(num);
    printf("\n");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count_test(num, true);
    count(num);
    printf("\n");
}