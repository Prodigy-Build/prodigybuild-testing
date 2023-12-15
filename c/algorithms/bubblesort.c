```c
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

bool is_sorted(int *array, int len)
{
    for (int i = 0; i < len - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void test_bubble_sort()
{
    int arr[] = {5, 2, 8, 4, 9, 1};
    int expected[] = {1, 2, 4, 5, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);

    if (is_sorted(arr, len)) {
        printf("Bubble sort test passed\n");
    } else {
        printf("Bubble sort test failed\n");
    }
}

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    
    test_bubble_sort();
    
    return 0;
}
```