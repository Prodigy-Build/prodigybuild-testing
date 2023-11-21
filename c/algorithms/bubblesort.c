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
    int arr1[] = {9, 5, 2, 7, 1};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, len1);
    for (int i = 0; i < len1 - 1; i++) {
        assert(arr1[i] <= arr1[i + 1]);
    }

    // Test case 2
    int arr2[] = {3, 1, 2};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);
    for (int i = 0; i < len2 - 1; i++) {
        assert(arr2[i] <= arr2[i + 1]);
    }

    // Test case 3
    int arr3[] = {6, 8, 4, 2, 7, 3};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);
    for (int i = 0; i < len3 - 1; i++) {
        assert(arr3[i] <= arr3[i + 1]);
    }
}

int main(void) 
{
    test_bubble_sort();
    printf("All test cases passed.\n");
    return 0;
}