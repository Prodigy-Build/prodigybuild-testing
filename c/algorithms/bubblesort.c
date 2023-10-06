#include <stdio.h>
#include <stdbool.h>
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
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr1, 10);
    assert(arr1[0] == 0);
    assert(arr1[1] == 1);
    assert(arr1[2] == 2);
    assert(arr1[3] == 3);
    assert(arr1[4] == 4);
    assert(arr1[5] == 6);
    assert(arr1[6] == 7);
    assert(arr1[7] == 8);
    assert(arr1[8] == 9);
    assert(arr1[9] == 10);

    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(arr2, 10);
    assert(arr2[0] == 0);
    assert(arr2[1] == 1);
    assert(arr2[2] == 2);
    assert(arr2[3] == 3);
    assert(arr2[4] == 4);
    assert(arr2[5] == 5);
    assert(arr2[6] == 6);
    assert(arr2[7] == 7);
    assert(arr2[8] == 8);
    assert(arr2[9] == 9);

    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubble_sort(arr3, 10);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);
    assert(arr3[3] == 4);
    assert(arr3[4] == 5);
    assert(arr3[5] == 6);
    assert(arr3[6] == 7);
    assert(arr3[7] == 8);
    assert(arr3[8] == 9);
    assert(arr3[9] == 10);
}

int main(void) 
{
    test_bubble_sort();
    
    printf("All tests passed.\n");
    
    return 0;
}