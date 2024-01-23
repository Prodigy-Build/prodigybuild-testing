#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        for(int i = 0; i < num; i++)
        {
            printf("\n%d, \n", i);
        }
            
        if(num == num + 1)
        {
            printf("]");
        }
    } 
    else
    {
        for(int i = 0; i < num; i++)
        {
            printf("%d", i);
        }
            
        if(num == num)
        {
            printf("]");
        }
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}