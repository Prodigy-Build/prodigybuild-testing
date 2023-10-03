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

void test_bubble_sort() {
    // Test Case 1
    int arr1[] = {5, 2, 8, 3, 9};
    bubble_sort(arr1, 5);
    assert(arr1[0] == 2);
    assert(arr1[1] == 3);
    assert(arr1[2] == 5);
    assert(arr1[3] == 8);
    assert(arr1[4] == 9);

    // Test Case 2
    int arr2[] = {1, 1, 1, 1, 1};
    bubble_sort(arr2, 5);
    assert(arr2[0] == 1);
    assert(arr2[1] == 1);
    assert(arr2[2] == 1);
    assert(arr2[3] == 1);
    assert(arr2[4] == 1);

    // Test Case 3
    int arr3[] = {9, 8, 7, 6, 5};
    bubble_sort(arr3, 5);
    assert(arr3[0] == 5);
    assert(arr3[1] == 6);
    assert(arr3[2] == 7);
    assert(arr3[3] == 8);
    assert(arr3[4] == 9);
}

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(yarr) / sizeof(yarr[0]);

    bubble_sort(yarr, len);

    printf("[");
    for (int i = 0; i < len; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");

    test_bubble_sort();

    return 0;
}
```