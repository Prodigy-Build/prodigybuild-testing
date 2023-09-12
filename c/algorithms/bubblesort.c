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

void test_bubble_sort(void) {
    int array1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int sorted1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(array1, 10);
    for (int i = 0; i < 10; i++) assert(array1[i] == sorted1[i]);

    int array2[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int sorted2[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    bubble_sort(array2, 10);
    for (int i = 0; i < 10; i++) assert(array2[i] == sorted2[i]);
}

int main(void)
{
    test_bubble_sort();

    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", arr[i]); 
    printf("\b\b]\n");
    return 0;
}