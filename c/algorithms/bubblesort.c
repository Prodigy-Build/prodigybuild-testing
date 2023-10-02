```c
#include <stdio.h>
#include <stddef.h>
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

void test_bubble_sort() 
{
    int array1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len1 = sizeof(array1) / sizeof(array1[0]);
    bubble_sort(array1, len1);
    
    int sorted_array1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    for (int i = 0; i < len1; i++) {
        assert(array1[i] == sorted_array1[i]);
    }
    
    int array2[] = {5};
    int len2 = sizeof(array2) / sizeof(array2[0]);
    bubble_sort(array2, len2);
    
    int sorted_array2[] = {5};
    for (int i = 0; i < len2; i++) {
        assert(array2[i] == sorted_array2[i]);
    }
    
    int array3[] = {};
    int len3 = sizeof(array3) / sizeof(array3[0]);
    bubble_sort(array3, len3);
    
    int sorted_array3[] = {};
    for (int i = 0; i < len3; i++) {
        assert(array3[i] == sorted_array3[i]);
    }
    
    int array4[] = {2, 1};
    int len4 = sizeof(array4) / sizeof(array4[0]);
    bubble_sort(array4, len4);
    
    int sorted_array4[] = {1, 2};
    for (int i = 0; i < len4; i++) {
        assert(array4[i] == sorted_array4[i]);
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
```