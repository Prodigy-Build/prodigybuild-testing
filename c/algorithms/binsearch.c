#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    
    if(element == mid)
        printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int isPrime(int n)
{
    if(n <= 1)
        return 0;
        
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    
    return 1;
}

int main()
{
    int num1, num2;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    if(isPrime(num1) && isPrime(num2))
        printf("Sum of %d and %d is %d", num1, num2, num1 + num2);
    else
        printf("Both numbers are not prime.");
        
    return 0;
}