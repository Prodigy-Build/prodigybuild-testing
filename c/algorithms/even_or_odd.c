#include <stdio.h>
#include <stdbool.h>

bool isEven(int num);

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if (isEven(num) == true)
    {
        printf("Even");
    }
    else
    {
        printf("Odd");
    }
    
    return 0;
}

bool isEven(int num)
{
    int rem = num % 2;
    
    if (rem == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}