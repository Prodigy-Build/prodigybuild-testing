#include <stdio.h>
#include <stdbool.h>

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

void test_bubble_sort() {
    int test1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(test1, 10);
    for (int i = 0; i < 10; i++) {
        if (test1[i] != expected1[i]) {
            printf("Test case 1 failed\n");
            return;
        }
    }
    printf("Test case 1 passed\n");
    
    int test2[] = {5, 4, 3, 2, 1};
    int expected2[] = {1, 2, 3, 4, 5};
    bubble_sort(test2, 5);
    for (int i = 0; i < 5; i++) {
        if (test2[i] != expected2[i]) {
            printf("Test case 2 failed\n");
            return;
        }
    }
    printf("Test case 2 passed\n");
    
    int test3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    bubble_sort(test3, 5);
    for (int i = 0; i < 5; i++) {
        if (test3[i] != expected3[i]) {
            printf("Test case 3 failed\n");
            return;
        }
    }
    printf("Test case 3 passed\n");
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}