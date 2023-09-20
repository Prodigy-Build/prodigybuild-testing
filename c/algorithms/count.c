#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_elements(int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf(i != num - 1 ? "%d, " : "%d", i);
    }
}

void count(int num) 
{
    printf("[");
    
    num > 20 ? print_elements(num) : printf("\n");
    
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