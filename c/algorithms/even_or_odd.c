#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    int rem = num % 2;
    
    if(rem == 0)
    {
        printf("Even");
    }
    else
    {
        printf("Odd");
    }
    return 0;
}