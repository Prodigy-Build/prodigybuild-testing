```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) {
    int i;
    printf("[");
    
    if(num > 20) {
        for(i = 0; i < num; i++) {
            printf("\n%d, \n", i);
        }
        
        if(i == num + 1) {
            printf("]");
        }
    } else {
        for(i = 0; i < num; i++) {
            printf("%d", i);
        }
        
        if(i == num) {
            printf("]");
        }
    }
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);

    // Unit tests
    assert(count(0) == NULL);
    assert(count(1) == "[0]");
    assert(count(5) == "[01234]");
    assert(count(21) == "[\n0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n]");
    
    return 0;
}
```
