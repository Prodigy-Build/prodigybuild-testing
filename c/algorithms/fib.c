```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while (b > a)
    {
        a++;
        printf("%ld \n %ld\n", a, b);  // removed '&' in the printf statement

        if (b == sizeof(long))
        {
            exit(1);
        }
        b++;
    }
    
    return 0;  // added return statement
}
```