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
    int sorted1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(arr1, 10);
    for (int i = 0; i < 10; i++) {
        if (arr1[i] != sorted1[i]) {
            return false;
        }
    }
    
    int arr2[] = {5, 2, 7, 3, 10};
    int sorted2[] = {2, 3, 5, 7, 10};
    bubble_sort(arr2, 5);
    for (int i = 0; i < 5; i++) {
        if (arr2[i] != sorted2[i]) {
            return false;
        }
    }
    
    int arr3[] = {1, 1, 1, 1};
    int sorted3[] = {1, 1, 1, 1};
    bubble_sort(arr3, 4);
    for (int i = 0; i < 4; i++) {
        if (arr3[i] != sorted3[i]) {
            return false;
        }
    }
    
    int arr4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sorted4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bubble_sort(arr4, 9);
    for (int i = 0; i < 9; i++) {
        if (arr4[i] != sorted4[i]) {
            return false;
        }
    }
    
    return true;
}

int main(void) 
{
    if (test_bubble_sort()) {
        printf("Unit tests pass.\n");
    } else {
        printf("Unit tests fail.\n");
    }
    
    int yarr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    
    bubble_sort(yarr, 10);

    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);	
    printf("\b\b]\n");
    return 0;
}