```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

// Unit test cases
void test_quick_sort()
{
    // Test case 1
    int arr1[] = {5, 8, 2, 1, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    quick_sort(arr1, 0, size1 - 1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 5);
    assert(arr1[3] == 7);
    assert(arr1[4] == 8);
    
    // Test case 2
    int arr2[] = {10, 5, 3, 8, 2, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    quick_sort(arr2, 0, size2 - 1);
    assert(arr2[0] == 2);
    assert(arr2[1] == 3);
    assert(arr2[2] == 5);
    assert(arr2[3] == 7);
    assert(arr2[4] == 8);
    assert(arr2[5] == 10);
}

int main()
{
    // Run unit test cases
    test_quick_sort();
    
    int size;
    printf("Size: ");
    scanf("%d", &size);
    
    int *arr = malloc(size * sizeof(int));
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    quick_sort(arr, 0, size - 1);
    
    printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;
    
    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }
    
    swap(&a[p], &a[j]);
    
    return j;
}

void quick_sort(int a[], int l, int h)
{
    int p;
    
    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }
    
    return;
}
```