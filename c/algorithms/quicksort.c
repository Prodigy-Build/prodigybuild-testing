#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

int main()
{
    // Test Case 1
    int size1 = 5;
    int arr1[] = {4, 2, 1, 3, 5};
    quick_sort(arr1, 0, size1 - 1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 4);
    assert(arr1[4] == 5);

    // Test Case 2
    int size2 = 10;
    int arr2[] = {9, 2, 1, 7, 5, 10, 8, 3, 6, 4};
    quick_sort(arr2, 0, size2 - 1);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    assert(arr2[3] == 4);
    assert(arr2[4] == 5);
    assert(arr2[5] == 6);
    assert(arr2[6] == 7);
    assert(arr2[7] == 8);
    assert(arr2[8] == 9);
    assert(arr2[9] == 10);

    // Test Case 3
    int size3 = 3;
    int arr3[] = {3, 2, 1};
    quick_sort(arr3, 0, size3 - 1);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);

    printf("All test cases passed!\n");
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