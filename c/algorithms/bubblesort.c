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
    int arr[] = {-2, 0, -5, 10, 8};
    bubble_sort(arr, 5);
    assert(arr[0] == -5 && arr[1] == -2 && arr[2] == 0 && arr[3] == 8 && arr[4] == 10);
    
    int arr2[] = {1, 1, 1, 1, 1};
    bubble_sort(arr2, 5);
    assert(arr2[0] == 1 && arr2[1] == 1 && arr2[2] == 1 && arr2[3] == 1 && arr2[4] == 1);
    
    int arr3[] = {3, 5, 2, 1, 7, 8, 6, 0, 4, 9};
    bubble_sort(arr3, 10);
    assert(arr3[0] == 0 && arr3[1] == 1 && arr3[2] == 2 && arr3[3] == 3 && arr3[4] == 4 && arr3[5] == 5 && arr3[6] == 6 && arr3[7] == 7 && arr3[8] == 8 && arr3[9] == 9);
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}