```c
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
    printf("Unit Test Cases:\n");
    printf("---------------------------\n");
    
    int num1 = 10;
    count(num1);
    printf("\nExpected Output: [0123456789]\n");
    
    int num2 = 25;
    count(num2);
    printf("\nExpected Output:\n\n0, \n1, \n2, \n3, \n4, \n5, \n6, \n7, \n8, \n9, \n10, \n11, \n12, \n13, \n14, \n15, \n16, \n17, \n18, \n19, \n20, \n21, \n22, \n23, \n24, \n]\n");
}

int main() {
    test_count();
    
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}
```