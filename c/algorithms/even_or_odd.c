#include <stdio.h>
#include <stdbool.h>

bool isEven(int num);

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if(isEven(num))
        printf("Even");
    else
        printf("Odd");
}

bool isEven(int num)
{
    int rem = num % 2;
    
    return rem == 0;
}