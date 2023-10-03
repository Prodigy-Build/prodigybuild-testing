#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_quick_sort()
{
    // Test case 1
    int arr1[] = {5, 2, 7, 1, 3};
    int size1 = sizeof(arr1) / sizeof(int);
    quick_sort(arr1, 0, size1 - 1);
    int expected1[] = {1, 2, 3, 5, 7};
    for (int i = 0; i < size1; i++)
    {
        assert(arr1[i] == expected1[i]);
    }

    // Test case 2
    int arr2[] = {10, 5, 8, 2, 4, 16, 1};
    int size2 = sizeof(arr2) / sizeof(int);
    quick_sort(arr2, 0, size2 - 1);
    int expected2[] = {1, 2, 4, 5, 8, 10, 16};
    for (int i = 0; i < size2; i++)
    {
        assert(arr2[i] == expected2[i]);
    }

    // Test case 3
    int arr3[] = {3, 1, 4, 1, 2, 5};
    int size3 = sizeof(arr3) / sizeof(int);
    quick_sort(arr3, 0, size3 - 1);
    int expected3[] = {1, 1, 2, 3, 4, 5};
    for (int i = 0; i < size3; i++)
    {
        assert(arr3[i] == expected3[i]);
    }
}

int main()
{
    test_quick_sort();
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
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
}