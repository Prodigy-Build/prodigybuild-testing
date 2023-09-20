#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VALUE 20

void count(int num) 
{
    int i;
    bool is_print_new_line = num > MAX_VALUE;
    
    printf("[");

    for(i = 0; i < num; i++)
    {
        if(is_print_new_line)
        {
            printf("\n%d, ", i);
        }
        else 
        {
            printf("%d", i);
            if(i != num - 1)
            {
                printf(", ");
            }
        }
    }

    printf("]\n");
}

int main()
{
    int num;
    
    printf("Count:~$ ");
    scanf("%d", &num);
    
    count(num);

    return 0;
}
