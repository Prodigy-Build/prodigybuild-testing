#include <stdio.h>

int evenOrOdd(int num)
{
    if(num % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if(evenOrOdd(num))
        printf("Even");
    else
        printf("Odd");
    
    return 0;
}