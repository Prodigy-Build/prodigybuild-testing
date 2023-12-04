#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) 
{
    printf("[");
    
    for(int i = 0; i < num; i++)
    {
        printf("%d", i);
        if(i != num - 1)
        {
            printf(", ");
        }
    }
    
    printf("]");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}