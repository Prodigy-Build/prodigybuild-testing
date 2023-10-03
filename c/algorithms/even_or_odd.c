#include <stdio.h>
#include <stdbool.h>

bool is_even(int num);

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d", &num);

    if (is_even(num)) {
        printf("Even");
    } else {
        printf("Odd");
    }
    return 0;
}

bool is_even(int num)
{
    return num % 2 == 0;
}