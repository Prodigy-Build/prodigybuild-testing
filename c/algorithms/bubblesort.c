#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int len) 
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(yarr) / sizeof(int);
    
    bubble_sort(yarr, len);

    printf("[");
    for (int i = 0; i < len; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}

// Unit Test Cases

void test_bubble_sort_case1() {
    int array[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int len = sizeof(array) / sizeof(int);
    
    bubble_sort(array, len);
    
    for (int i = 0; i < len; i++) {
        if (array[i] != expected[i]) {
            printf("Test case 1 failed");
            return;
        }
    }
    
    printf("Test case 1 passed");
}

void test_bubble_sort_case2() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(array) / sizeof(int);
    
    bubble_sort(array, len);
    
    for (int i = 0; i < len; i++) {
        if (array[i] != expected[i]) {
            printf("Test case 2 failed");
            return;
        }
    }
    
    printf("Test case 2 passed");
}

void test_bubble_sort_case3() {
    int array[] = {1};
    int expected[] = {1};
    int len = sizeof(array) / sizeof(int);
    
    bubble_sort(array, len);
    
    for (int i = 0; i < len; i++) {
        if (array[i] != expected[i]) {
            printf("Test case 3 failed");
            return;
        }
    }
    
    printf("Test case 3 passed");
}

int main(void) {
    test_bubble_sort_case1();
    test_bubble_sort_case2();
    test_bubble_sort_case3();
    
    return 0;
}