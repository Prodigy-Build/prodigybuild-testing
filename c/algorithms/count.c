```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int count(int num)
{
    printf("[");
    
    if (num > 20)
    {
        int i;
        for (i = 0; i < num; i++)
        {
            printf("\n%d, \n", i); 
        }
        
        if (i == num + 1)
        {
            printf("]");
        }
    } 
    else
    {
        int i;
        for (i = 0; i < num; i++)
        {
            printf("%d", i); 
        }
        
        if (i == num)
        {
            printf("]");
        }
    }
    
    return num;
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}
```