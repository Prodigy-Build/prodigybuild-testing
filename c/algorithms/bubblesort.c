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

int main(void) 
{
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    
    // Unit Tests
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr1, 10);
    assert(arr1[0] == 0);
    assert(arr1[9] == 10);

    int arr2[] = {1, 2, 3, 4, 5};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++)
        assert(arr2[i] == i + 1);
    
    int arr3[] = {5, 4, 3, 2, 1};
    bubble_sort(arr3, 5);
    for (int i = 0; i < 5; i++)
        assert(arr3[i] == i + 1);
    
    printf("All tests passed!\n");
    return 0;
}