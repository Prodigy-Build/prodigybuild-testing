#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("%d%s", i, (i < num - 1) ? (num > 20 ? ", \n" : ", ") : "]");
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    printf("[");
    count(num);
}