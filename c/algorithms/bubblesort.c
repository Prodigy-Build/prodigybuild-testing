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

bool test_bubble_sort() {
    int arr[] = {10, 7, 8, 1, 5};
    int expected[] = {1, 5, 7, 8, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);

    for (int i = 0; i < len; i++) {
        if (arr[i] != expected[i]) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    assert(test_bubble_sort());

    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}