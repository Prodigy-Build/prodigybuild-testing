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
    int arr[] = {5, 2, 7, 3, 1};
    int sorted_arr[] = {1, 2, 3, 5, 7};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == sorted_arr[i]);
    }
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