```c/algorithms/count.c``` updated:

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) {
    printf("[");
    
    for(int i = 0; i < num; i++) {
        if(num > 20) {
            printf("\n%d, \n", i);
        } else {
            printf("%d", i);
        }
    }
    
    if(num > 20 && num == i) {
        printf("]");
    } else if(num <= 20 && num == i) {
        printf("]");
    }
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}
```