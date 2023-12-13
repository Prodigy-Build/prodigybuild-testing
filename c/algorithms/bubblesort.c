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
    // Test case 1
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int expected1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(arr1, 10);
    for (int i = 0; i < 10; i++) {
        assert(arr1[i] == expected1[i]);
    }

    // Test case 2
    int arr2[] = {5, 4, 3, 2, 1};
    int expected2[] = {1, 2, 3, 4, 5};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr2[i] == expected2[i]);
    }

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    bubble_sort(arr3, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr3[i] == expected3[i]);
    }
}

int main(void) 
{
    test_bubble_sort();

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}