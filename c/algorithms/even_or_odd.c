#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[10], int element);

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int rem = num % 2;
    
    if (rem == 0)
        printf("Even");
    else
        printf("Odd");

    return 0;
}