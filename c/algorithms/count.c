#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printNums(int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("%d ", i);
    }
}

void count(int num) {
    printf("[");

    if (num > 20) {
        printNums(num);
    } else {
        printNums(num);
    }
    
    printf("]");
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    
    return 0;
}