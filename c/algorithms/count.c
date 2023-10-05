```c
#include <stdio.h>

void count(int num) 
{
    printf("[");
    
    if (num > 20) 
    {
        for (int i = 0; i < num; i++) 
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
        for (int i = 0; i < num; i++) 
        {
            printf("%d", i);
        }
        
        if (i == num)
        {
            printf("]");
        }
    }
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