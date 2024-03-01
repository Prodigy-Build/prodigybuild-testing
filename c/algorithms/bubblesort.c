#include <stdio.h>
#include <stdbool.h>

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
    printf("Sorted array 1: [");
    for (int i = 0; i < len1; i++)
        printf("%d, ", arr1[i]);
    printf("\b\b]\n");

    // Test case 2
    int arr2[] = {5, 2, 7, 1, 9, 3};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);
    printf("Sorted array 2: [");
    for (int i = 0; i < len2; i++)
        printf("%d, ", arr2[i]);
    printf("\b\b]\n");

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);
    printf("Sorted array 3: [");
    for (int i = 0; i < len3; i++)
        printf("%d, ", arr3[i]);
    printf("\b\b]\n");
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}