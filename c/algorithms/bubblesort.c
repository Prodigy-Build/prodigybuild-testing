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
    bubble_sort(arr1, 10);
    assert(arr1[0] == 0);
    assert(arr1[1] == 1);
    assert(arr1[2] == 2);
    assert(arr1[3] == 3);
    assert(arr1[4] == 4);
    assert(arr1[5] == 6);
    assert(arr1[6] == 7);
    assert(arr1[7] == 8);
    assert(arr1[8] == 9);
    assert(arr1[9] == 10);
    
    int arr2[] = {4, 3, 2, 1};
    bubble_sort(arr2, 4);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    assert(arr2[3] == 4);
    
    int arr3[] = {1};
    bubble_sort(arr3, 1);
    assert(arr3[0] == 1);
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