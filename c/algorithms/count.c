#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printCount(int num, int isGreater) 
{
    for(int i = 0; i < num; i++)
    {
        if(isGreater)
        {
            printf("\n%d, \n", i);
        }
        else
        {
            printf("%d", i);
        }
    }
}

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        printCount(num, 1);
        printf("]");
    } else
    {
        printCount(num, 0);
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