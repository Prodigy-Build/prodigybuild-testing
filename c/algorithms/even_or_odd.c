#include <stdio.h>
#include <assert.h>

int even_or_odd(long num) {
    int rem = num % 2;
    
    if (rem == 0)
        return 1;
    else
        return 0;
}

int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);

    int result = even_or_odd(num);
    if (result)
        printf("Even");
    else
        printf("Odd");

    return 0;
}