#include <stdio.h>

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    int prime1 = 2;
    int prime2 = 3;
    int sum = prime1 + prime2;

    if (isPrime(prime1) && isPrime(prime2))
    {
        printf("The sum of %d and %d is %d", prime1, prime2, sum);
    }
    
    return 0;
}