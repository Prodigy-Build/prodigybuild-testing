#include <stdio.h>
#include <stdbool.h>

bool isEven(int num) {
    if(num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

void test_isEven() {
    printf("%s\n", isEven(2) ? "pass" : "fail");
    printf("%s\n", isEven(5) ? "fail" : "pass");
    printf("%s\n", isEven(10) ? "pass" : "fail");
    printf("%s\n", isEven(13) ? "fail" : "pass");
    printf("%s\n", isEven(50) ? "pass" : "fail");
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    
    if(rem == 0)
    printf("Even");
    else
    printf("Odd");
    
    test_isEven();
    
    return 0;
}