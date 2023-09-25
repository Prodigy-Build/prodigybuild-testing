#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int *array, int len);

void test_bubble_sort(void)
{
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, len1);
    for (int i = 0; i < len1 - 1; i++) {
        if (arr1[i] > arr1[i + 1]) {
            printf("Test failed.\n");
            return;
        }
    }
    
    int arr2[] = {1, 2, 3, 4, 5};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);
    for (int i = 0; i < len2 - 1; i++) {
        if (arr2[i] > arr2[i + 1]) {
            printf("Test failed.\n");
            return;
        }
    }
    
    int arr3[] = {5, 4, 3, 2, 1};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);
    for (int i = 0; i < len3 - 1; i++) {
        if (arr3[i] > arr3[i + 1]) {
            printf("Test failed.\n");
            return;
        }
    }
    
    printf("All tests passed.\n");
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}

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