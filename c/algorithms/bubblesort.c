#include <stdio.h>
#include <assert.h>

void bubble_sort(int *array, int len) 
{
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < len - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void test_bubble_sort() 
{
    int arr1[] = {5, 2, 9, 4, 7};
    bubble_sort(arr1, 5);
    assert(arr1[0] == 2);
    assert(arr1[1] == 4);
    assert(arr1[2] == 5);
    assert(arr1[3] == 7);
    assert(arr1[4] == 9);

    int arr2[] = {1, 3, 5, 7, 9};
    bubble_sort(arr2, 5);
    assert(arr2[0] == 1);
    assert(arr2[1] == 3);
    assert(arr2[2] == 5);
    assert(arr2[3] == 7);
    assert(arr2[4] == 9);

    int arr3[] = {10, 8, 6, 4, 2};
    bubble_sort(arr3, 5);
    assert(arr3[0] == 2);
    assert(arr3[1] == 4);
    assert(arr3[2] == 6);
    assert(arr3[3] == 8);
    assert(arr3[4] == 10);
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