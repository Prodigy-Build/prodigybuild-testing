#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count(int num) {
    printf("[");
    
    for(int i = 0; i < num; i++) {
        printf("\n%d, \n", i);
    }
    
    if(num == 0) {
        printf("%d", 0);
    }
    
    printf("]");
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}