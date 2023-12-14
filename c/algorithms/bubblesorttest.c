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

bool test_bubble_sort()
{
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int sorted_arr1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    
    bubble_sort(arr1, 10);
    
    for (int i = 0; i < 10; i++) {
        if (arr1[i] != sorted_arr1[i])
            return false;
    }
    
    int arr2[] = {5, 2, 1, 8, 10, 6, 3, 4, 7, 9};
    int sorted_arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    bubble_sort(arr2, 10);
    
    for (int i = 0; i < 10; i++) {
        if (arr2[i] != sorted_arr2[i])
            return false;
    }
    
    return true;
}

int main(void) 
{
    if (test_bubble_sort()) {
        printf("All test cases pass\n");
    } else {
        printf("Test cases fail\n");
    }
    
    return 0;
}