#include <stdio.h>

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
    return 0;
}

void test_bubble_sort(void) {
    // Test case 1
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr1, 10);
    
    // Test case 2
    int arr2[] = {2, 5, 1, 7, 3, 8, 4, 9, 6, 0};
    bubble_sort(arr2, 10);
    
    // Test case 3
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(arr3, 10);
    
    // Test case 4
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubble_sort(arr4, 10);
}
           
int main(void) 
{
    test_bubble_sort();
    return 0;
}