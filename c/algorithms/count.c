#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    int count = 0;
    int i;
    for(i = 0; i < num; i++)
    {
        printf("%d", i);
        count++;
    }
    
    if(count == num)
        printf("]");
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}