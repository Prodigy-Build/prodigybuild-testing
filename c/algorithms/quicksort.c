#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_swap();
void test_partition();
void test_quick_sort();

int main()
{
    test_swap();
    test_partition();
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

void test_swap()
{
    int a = 5;
    int b = 10;

    swap(&a, &b);
    assert(a == 10 && b == 5);
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

void test_partition()
{
    int arr[] = {7, 2, 8, 1, 3, 6, 5, 4};
    int pivot = partition(arr, 0, 7);

    assert(arr[pivot] == 4);
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

void test_quick_sort()
{
    int arr[] = {7, 2, 8, 1, 3, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    for (int i = 1; i < size; i++)
    {
        assert(arr[i] >= arr[i - 1]);
    }
}