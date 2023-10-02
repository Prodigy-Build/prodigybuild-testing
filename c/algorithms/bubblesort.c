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
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int sorted_arr1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(arr1, 10);
    
    for (int i = 0; i < 10; i++)
        assert(arr1[i] == sorted_arr1[i]);

    int arr2[] = {5, 2, 9, 1, 4};
    int sorted_arr2[] = {1, 2, 4, 5, 9};
    bubble_sort(arr2, 5);

    for (int i = 0; i < 5; i++)
        assert(arr2[i] == sorted_arr2[i]);
}

int main(void) 
{
    test_bubble_sort();

    printf("All test cases pass");
    return 0;
}