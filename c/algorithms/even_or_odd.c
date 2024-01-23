#include <stdio.h>

int even_or_odd(int num)
{
    int rem = num % 2;
    
    if(rem == 0)
        return 1; // Even
    else
        return 0; // Odd
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(even_or_odd(num))
        printf("Even\n");
    else
        printf("Odd\n");
    
    return 0;
}