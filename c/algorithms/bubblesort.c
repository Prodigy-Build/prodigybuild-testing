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
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, len1);
    int expected1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    for (int i = 0; i < len1; i++) {
        assert(arr1[i] == expected1[i]);
    }
    
    // Test case 2
    int arr2[] = {5};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);
    int expected2[] = {5};
    for (int i = 0; i < len2; i++) {
        assert(arr2[i] == expected2[i]);
    }
    
    // Test case 3
    int arr3[] = {3, 1, 2};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);
    int expected3[] = {1, 2, 3};
    for (int i = 0; i < len3; i++) {
        assert(arr3[i] == expected3[i]);
    }
    
    // Test case 4
    int arr4[] = {};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);
    bubble_sort(arr4, len4);
    int expected4[] = {};
    for (int i = 0; i < len4; i++) {
        assert(arr4[i] == expected4[i]);
    }
}

int main(void) 
{
    test_bubble_sort();
    
    return 0;
}