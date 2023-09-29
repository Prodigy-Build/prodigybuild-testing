#include <stdio.h>
#include <assert.h>

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
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr1, 10);
    for (int i = 0; i < 10; i++) {
        assert(arr1[i] == i);
    }

    int arr2[] = {-5, 100, -50, 0, 10};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr2[i] == i - 5);
    }
}

int main(void) 
{
    test_bubble_sort();
    printf("All test cases passed!\n");
    return 0;
}