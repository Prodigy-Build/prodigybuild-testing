#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
        {
            if(i != num - 1)
                printf("\n%d, ", i);
            else
                printf("\n%d", i);
        }
            
        if(i == num + 1)
            printf("]");
    } 
    else
    {
        int i;
        for(i = 0; i < num; i++)
        {
            if(i != num - 1)
                printf("%d, ", i);
            else
                printf("%d", i);
        }
            
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

