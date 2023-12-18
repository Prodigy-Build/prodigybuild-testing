#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <stdbool.h>

#include <string.h>

#include <assert.h>

int count(int num) {

    printf("[");

    if(num > 20) {

        int i;

        for(i = 0; i < num; i++) {

            printf(" %d, ", i);

        }

        

        if(i == num + 1) {

            printf("]");

        }

    } else {

        int i;

        for(i = 0; i < num; i++) {

            printf(" %d", i);

        }

        

        if(i == num) {

            printf("]");

        }

    }

}

void test_count() {

    printf("Testing count function\n");

    printf("----------------------\n");

    

    printf("Test case 1: num = 10\n");

    printf("Expected Output: [ 0 1 2 3 4 5 6 7 8 9 ]\n");

    count(10);

    printf("\n");

    

    printf("Test case 2: num = 25\n");

    printf("Expected Output: [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 ]\n");

    count(25);

    printf("\n");

    

    printf("Test case 3: num = 5\n");

    printf("Expected Output: [ 0 1 2 3 4 ]\n");

    count(5);

    printf("\n");

}

int main() {

    test_count();

    return 0;

}