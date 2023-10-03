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

void test_bubble_sort() {
    int arr1[] = {1, 2, 3, 4, 5};
    bubble_sort(arr1, 5);
    for (int i = 0; i < 5; i++)
        assert(arr1[i] == i + 1);
    
    int arr2[] = {5, 4, 3, 2, 1};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++)
        assert(arr2[i] == i + 1);
    
    int arr3[] = {3, 7, 2, 6, 5, 4, 1};
    bubble_sort(arr3, 7);
    for (int i = 0; i < 7; i++)
        assert(arr3[i] == i + 1);
    
    int arr4[] = {0};
    bubble_sort(arr4, 1);
    assert(arr4[0] == 0);
    
    int arr5[] = {};
    bubble_sort(arr5, 0);
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