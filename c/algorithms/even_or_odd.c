```c
#include <stdio.h>

int isEvenOrOdd(long num) {
    int rem = num % 2;
    
    if(rem == 0)
        return 1; // Even
    else
        return 0; // Odd
}

void test_isEvenOrOdd() {
    // Test case 1: Even number
    printf("Test case 1: %d\n", isEvenOrOdd(6));
    
    // Test case 2: Odd number
    printf("Test case 2: %d\n", isEvenOrOdd(9));
    
    // Test case 3: Negative even number
    printf("Test case 3: %d\n", isEvenOrOdd(-10));
    
    // Test case 4: Negative odd number
    printf("Test case 4: %d\n", isEvenOrOdd(-15));
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if (isEvenOrOdd(num))
        printf("Even");
    else
        printf("Odd");
    
    return 0;
}
```