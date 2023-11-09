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
    // Test case 1
    int arr1[] = {4, 2, 5, 1, 3};
    bubble_sort(arr1, 5);
    int sorted_arr1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        assert(arr1[i] == sorted_arr1[i]);

    // Test case 2
    int arr2[] = {9, 1, 6, 3, 2, 7, 8, 4, 5};
    bubble_sort(arr2, 9);
    int sorted_arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
        assert(arr2[i] == sorted_arr2[i]);

    // Test case 3
    int arr3[] = {1};
    bubble_sort(arr3, 1);
    int sorted_arr3[] = {1};
    for (int i = 0; i < 1; i++)
        assert(arr3[i] == sorted_arr3[i]);
}

int main(void) 
{
    test_bubble_sort();

    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}
```