#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_quick_sort()
{
    int arr1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    quick_sort(arr1, 0, size1 - 1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 1);
    assert(arr1[2] == 2);
    assert(arr1[3] == 3);
    assert(arr1[4] == 3);
    assert(arr1[5] == 4);
    assert(arr1[6] == 5);
    assert(arr1[7] == 5);
    assert(arr1[8] == 6);
    assert(arr1[9] == 9);

    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
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

    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    quick_sort(arr3, 0, size3 - 1);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 3);
    assert(arr3[3] == 4);
    assert(arr3[4] == 5);
    assert(arr3[5] == 6);
    assert(arr3[6] == 7);
    assert(arr3[7] == 8);
    assert(arr3[8] == 9);

    int arr4[] = {1};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    quick_sort(arr4, 0, size4 - 1);
    assert(arr4[0] == 1);

    printf("All test cases passed!\n");
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