```c
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

int main(void) 
{
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, len);

    printf("[");
    for (int i = 0; i < len; i++)
        printf("%d, ", arr[i]);	
    printf("\b\b]\n");
    return 0;
}
```