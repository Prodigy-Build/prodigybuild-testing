```c
#include <stdio.h>

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    if ((num & 1) == 0)
        printf("Even");
    else
        printf("Odd");

    return 0;
}
```