#include <stdio.h>
#include <stdbool.h>

bool isEven(int);

int main()
{
    printf("Enter a number\n");
    int num;
    scanf("%d", &num);

    if(isEven(num))
        printf("Even");
    else
        printf("Odd");

    return 0;
}

bool isEven(int num)
{
    return num % 2 == 0;
}