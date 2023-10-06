```c
#include <stdio.h>
#include <stdbool.h>

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);
    
    if (isEven(num))
        printf("Even");
    else
        printf("Odd");
    
    return 0;
}
```