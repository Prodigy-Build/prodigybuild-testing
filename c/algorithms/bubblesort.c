```c
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
    int arr[] = { 5, 3, 8, 2, 1 };
    bubble_sort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 5);
    assert(arr[4] == 8);

    int arr2[] = { 1, 2, 3, 4, 5 };
    bubble_sort(arr2, 5);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    assert(arr2[3] == 4);
    assert(arr2[4] == 5);

    int arr3[] = { 9, 8, 7, 6, 5 };
    bubble_sort(arr3, 5);
    assert(arr3[0] == 5);
    assert(arr3[1] == 6);
    assert(arr3[2] == 7);
    assert(arr3[3] == 8);
    assert(arr3[4] == 9);
}

int main(void) 
{
    test_bubble_sort();

    printf("All test cases pass.\n");
    return 0;
}
```