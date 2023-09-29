'''c/algorithms/bubblesort.c'''

#include <stdio.h>

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
    int arr[] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 5);
    printf("[");
    for (int i = 0; i < 5; i++)
        printf("%d, ", arr[i]);
    printf("\b\b]\n");
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}