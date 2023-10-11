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
    int arr1[] = {6, 3, 8, 1, 9, 2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, len1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 6);
    assert(arr1[4] == 8);
    assert(arr1[5] == 9);
    
    int arr2[] = {5, 5, 5, 5, 5};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);
    assert(arr2[0] == 5);
    assert(arr2[1] == 5);
    assert(arr2[2] == 5);
    assert(arr2[3] == 5);
    assert(arr2[4] == 5);
    
    int arr3[] = {10, 9, 8, 7, 6, 5};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);
    assert(arr3[0] == 5);
    assert(arr3[1] == 6);
    assert(arr3[2] == 7);
    assert(arr3[3] == 8);
    assert(arr3[4] == 9);
    assert(arr3[5] == 10);
}

int main(void) 
{
    test_bubble_sort();
    
    printf("All tests pass\n");
    
    return 0;
}