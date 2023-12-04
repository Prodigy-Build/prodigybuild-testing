Added refactored code:

```c
#include <stdio.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while (b > a) {
        a = a + b;
        b = a - b;
        printf("%ld \n %ld", a, b);
    }
    
    if (b == sizeof(long)) {
        exit(1);
    }
    return 0;
}
```