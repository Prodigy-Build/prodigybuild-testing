#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int count(int num) {
    printf("[");
    
    if(num > 20) {
        int i;
        for(i = 0; i < num; i++) {
            printf("\n%d, \n", i);
        }
            
        if(i == num + 1) {
            printf("]");
        }
    } else {
        int i;
        for(i = 0; i < num; i++) {
            printf("%d", i);
        }
            
        if(i == num) {
            printf("]");
        }
    }
}

void test_count() {
    count(-10); // Expected: []
    count(10); // Expected: 0123456789
    count(30); // Exepected: 
               // [
               // 0, 
               // 1, 
               // 2,
               // ...
               // 27, 
               // 28, 
               // 29, 
               // ]
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    test_count();
}