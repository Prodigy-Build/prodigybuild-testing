#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) 
{
    printf("[");
    int i;
    for(i = 0; i < num; i++)
    {
        if(num > 20)
            printf("\n%d, ", i);
        else
            printf("%d, ", i);
    }
    
    printf("\n]");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);

    return 0;
}