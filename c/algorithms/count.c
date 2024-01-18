#include <stdio.h>
#include <stdlib.h>

void print_elements(int num, int newline) 
{
    int i;
    for(i = 0; i < num; i++)
    {
        if(newline)
            printf("\n%d, ", i);
        else
            printf("%d, ", i);
    }
    printf("\n]");
}

void count(int num) 
{
    printf("[");
    if(num > 20)
    {
        print_elements(num, 1);
    } else
    {
        print_elements(num, 0);
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}