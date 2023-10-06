#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    int result = 0;

    if (num > 20)
    {
        for (int i = 0; i < num; i++)
        {
            result += i;
        }
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            result += i;
        }
    }

    return result;
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);

    int res = count(num);
    printf("Result: %d\n", res);

    return 0;
}