#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) 
{
    printf("[");
    
    int i;
    for(i = 0; i < num; i++)
    {
        if(num > 20)
        {
            printf("%d,\n", i);
        }
        else 
        {
            printf("%d", i);
            if(i != num - 1)
            {
                printf(",");
            }
        }
    }
    printf("]\n");
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    count(num);
    return 0;
}