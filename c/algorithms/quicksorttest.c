#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_swap()
{
    int a = 1, b = 2;
    swap(&a, &b);
    assert(a == 2 && b == 1);
}

void test_partition()
{
    int arr[] = {4, 9, 2, 6, 5};
    int pivot_index = partition(arr, 0, 4);
    assert(arr[pivot_index] == 5);
}

void test_quick_sort()
{
    int arr[] = {4, 9, 2, 6, 5};
    quick_sort(arr, 0, 4);
    for (int i = 0; i < 4; i++)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

int main()
{
    test_swap();
    test_partition();
    test_quick_sort();

    printf("All tests pass!\n");

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