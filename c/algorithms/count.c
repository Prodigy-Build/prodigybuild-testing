#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    int countArr[num];
    
    if(num > 20)
    {
        for(int i = 0; i < num; i++)
            countArr[i] = i;
    } 
    else
    {
        for(int i = 0; i < num; i++)
            countArr[i] = i;
    }
    
    printf("[");
    
    for(int i = 0; i < num; i++)
    {
        printf("%d", countArr[i]);
        
        if(i != num - 1)
            printf(", ");
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