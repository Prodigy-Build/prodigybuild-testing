#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    int i;
    printf("[");

    if(num > 20)
    {
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } 
    else
    {
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

// This code is not testable.