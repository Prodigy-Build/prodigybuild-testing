#include <stdio.h>

int isEven(int num){
    return num % 2 == 0;
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    
    if(isEven(num))
        printf("Even");
    else
        printf("Odd");
        
    return 0;
}