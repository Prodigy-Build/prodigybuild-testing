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

void test_bubble_sort() 
{
    // Test case 1
    int arr1[] = {5, 2, 8, 4, 1};
    int sorted_arr1[] = {1, 2, 4, 5, 8};
    bubble_sort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr1[i] == sorted_arr1[i]);
    }

    // Test case 2
    int arr2[] = {10, 5, 3, 8, 6, 2};
    int sorted_arr2[] = {2, 3, 5, 6, 8, 10};
    bubble_sort(arr2, 6);
    for (int i = 0; i < 6; i++) {
        assert(arr2[i] == sorted_arr2[i]);
    }

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int sorted_arr3[] = {1, 2, 3, 4, 5};
    bubble_sort(arr3, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr3[i] == sorted_arr3[i]);
    }
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}