```c

#include <stdio.h>

int count(int num) 
{
    printf("[");
    
    for(int i = 0; i < num; i++)
    {
        if(i == num - 1)
            printf("%d", i);
        else
            printf("%d, ", i);
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
```