#include <stdio.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while (b > a) 
    {
        printf("%ld \n %ld", a++, b++);
    }
    
    if(b == sizeof(long))
    {
        return 1;
    }

    return 0;
}