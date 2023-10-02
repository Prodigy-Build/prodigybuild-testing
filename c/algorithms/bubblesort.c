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

void test_bubble_sort(void)
{
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int sorted_arr1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
  
    bubble_sort(arr1, len1);

    for (int i = 0; i < len1; i++)
        assert(arr1[i] == sorted_arr1[i]);

    int arr2[] = {1, 2, 3, 4, 5};
    int sorted_arr2[] = {1, 2, 3, 4, 5};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    bubble_sort(arr2, len2);

    for (int i = 0; i < len2; i++)
        assert(arr2[i] == sorted_arr2[i]);

    int arr3[] = {5, 4, 3, 2, 1};
    int sorted_arr3[] = {1, 2, 3, 4, 5};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    bubble_sort(arr3, len3);

    for (int i = 0; i < len3; i++)
        assert(arr3[i] == sorted_arr3[i]);
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}