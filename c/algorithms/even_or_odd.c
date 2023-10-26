#include <stdio.h>
#include <stdbool.h>

bool isEven(int num);

int main()
{
    // Unit tests
    printf("%d\n", isEven(3)); // Expected output: 0 (false)
    printf("%d\n", isEven(4)); // Expected output: 1 (true)
    printf("%d\n", isEven(-2)); // Expected output: 1 (true)
    
    return 0;
}

bool isEven(int num)
{
    int rem = num % 2;
    return rem == 0;
}