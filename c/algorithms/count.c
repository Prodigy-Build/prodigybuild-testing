#include <stdio.h>
#include <stdlib.h>

void count(int num) 
{
    printf("[");
    
    int i;
    char* separator = "";
    for(i = 0; i < num; i++)
    {
        printf("%s%d", separator, i);
        separator = num > 20 ? ",\n" : ",";
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