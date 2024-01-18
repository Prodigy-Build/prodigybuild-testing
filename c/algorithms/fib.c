#include <stdio.h>

long fibonacciSeries(long limit){
    long a = 0;
    long b = 1;
    long c;

    printf("%ld \n", a);
    printf("%ld \n", b);

    for(int i = 2; i <= limit; i++){
        c = a + b;
        printf("%ld \n", c);
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    long limit = sizeof(long);
    fibonacciSeries(limit);
    return 0;
}