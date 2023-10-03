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

void test_bubble_sort() 
{
    int arr[] = {3, 9, 4, 8, 7};
    bubble_sort(arr, 5);
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 7);
    assert(arr[3] == 8);
    assert(arr[4] == 9);
    
    int arr2[] = {5};
    bubble_sort(arr2, 1);
    assert(arr2[0] == 5);
    
    int arr3[] = {1, 2, 3, 4, 5};
    bubble_sort(arr3, 5);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);
    assert(arr3[3] == 4);
    assert(arr3[4] == 5);
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