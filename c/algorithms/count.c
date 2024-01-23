#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    printf("[");
    int i;
    for(i = 0; i < num; i++)
        printf("\n%d, \n", i);
    
    printf("]");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}