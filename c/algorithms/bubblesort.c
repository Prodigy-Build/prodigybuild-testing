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
    int arr[] = {5, 3, 7, 1, 9};
    bubble_sort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 3);
    assert(arr[2] == 5);
    assert(arr[3] == 7);
    assert(arr[4] == 9);
    
    int arr2[] = {5, 3};
    bubble_sort(arr2, 2);
    assert(arr2[0] == 3);
    assert(arr2[1] == 5);
    
    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(arr3, 9);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);
    assert(arr3[3] == 4);
    assert(arr3[4] == 5);
    assert(arr3[5] == 6);
    assert(arr3[6] == 7);
    assert(arr3[7] == 8);
    assert(arr3[8] == 9);
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}