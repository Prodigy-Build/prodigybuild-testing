#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

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

// Unit test cases
void test_quick_sort()
{
    // Test case 1
    int arr1[] = {4, 2, 8, 1, 6, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    quick_sort(arr1, 0, size1 - 1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 4);
    assert(arr1[4] == 6);
    assert(arr1[5] == 8);

    // Test case 2
    int arr2[] = {9, 5, 12, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    quick_sort(arr2, 0, size2 - 1);
    assert(arr2[0] == 5);
    assert(arr2[1] == 7);
    assert(arr2[2] == 9);
    assert(arr2[3] == 12);

    // Test case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    quick_sort(arr3, 0, size3 - 1);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);
    assert(arr3[3] == 4);
    assert(arr3[4] == 5);

    // Test case 4
    int arr4[] = {10};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    quick_sort(arr4, 0, size4 - 1);
    assert(arr4[0] == 10);
}

int main()
{
    test_quick_sort();
    return 0;
}