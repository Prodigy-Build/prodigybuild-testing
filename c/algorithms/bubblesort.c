.

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
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int arr2[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(arr1, 10);
    for (int i = 0; i < 10; i++) {
        assert(arr1[i] == arr2[i]);
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