#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

int count(int num) {
    printf("[");
    
    if(num > 20) {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
        
        if(i == num + 1)
            printf("]");
    } else {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
        
        if(i == num)
            printf("]");
    }
}

void test_count() {
    count(5);  // Expected output: [01234]
    
    count(25);  // Expected output:
                // [
                // 0,
                // 1,
                // 2,
                // ...
                // 22,
                // 23,
                // 24,
                // ]
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    test_count();
    
    return 0;
}