```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 0;
    long b = 1;
    
    while (1) {
        long temp = a + b;
        a = b;
        b = temp;
        
        printf("%ld \n", b);
        
        if (b == 0) {
            break;
        }
    }
    
    return 0;
}
```