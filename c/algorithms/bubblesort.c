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
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, len);

    assert(arr[0] == 0);
    assert(arr[1] == 1);
    assert(arr[2] == 2);
    assert(arr[3] == 3);
    assert(arr[4] == 4);
    assert(arr[5] == 6);
    assert(arr[6] == 7);
    assert(arr[7] == 8);
    assert(arr[8] == 9);
    assert(arr[9] == 10);
}

int main(void) 
{
    test_bubble_sort();

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}