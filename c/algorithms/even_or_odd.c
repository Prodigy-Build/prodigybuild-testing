```c
#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number: ");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if (rem == 0) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }
}
```