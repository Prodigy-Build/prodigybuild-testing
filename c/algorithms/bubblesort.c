```c
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
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(arr1, 10);
    for (int i = 0; i < 10; i++)
        assert(arr1[i] == i);

    int arr2[] = {5, 2, 9, 6, 1, 3, 4, 8, 7, 0};
    bubble_sort(arr2, 10);
    for (int i = 0; i < 10; i++)
        assert(arr2[i] == i);

    int arr3[] = {1, 2, 3, 4, 5};
    bubble_sort(arr3, 5);
    for (int i = 0; i < 5; i++)
        assert(arr3[i] == i + 1);

    int arr4[] = {5, 4, 3, 2, 1};
    bubble_sort(arr4, 5);
    for (int i = 0; i < 5; i++)
        assert(arr4[i] == i + 1);

    int arr5[] = {1};
    bubble_sort(arr5, 1);
    assert(arr5[0] == 1);

    int arr6[] = {};
    bubble_sort(arr6, 0);
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
```