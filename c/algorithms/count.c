#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printNumbers(int start, int end) {
    for (int i = start; i < end; i++) {
        if (i > start) {
            printf(", ");
        }
        printf("%d", i);
    }
}

void count(int num) {
    printf("[");

    if (num > 20) {
        printNumbers(0, num);
        if (num > 0) {
            printf(", ");
        }
        printf("%d", num);
    } else {
        printNumbers(0, num);
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