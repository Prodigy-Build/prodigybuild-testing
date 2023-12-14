#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_swap()
{
    int a = 5;
    int b = 10;
    swap(&a, &b);
    assert(a == 10);
    assert(b == 5);
}

void test_partition()
{
    int arr[5] = {10, 7, 8, 9, 1};
    int result = partition(arr, 0, 4);
    assert(result == 0);
    assert(arr[0] == 1);
    assert(arr[1] == 7);
    assert(arr[2] == 8);
    assert(arr[3] == 9);
    assert(arr[4] == 10);
}

void test_quick_sort()
{
    int arr[5] = {10, 7, 8, 9, 1};
    quick_sort(arr, 0, 4);
    assert(arr[0] == 1);
    assert(arr[1] == 7);
    assert(arr[2] == 8);
    assert(arr[3] == 9);
    assert(arr[4] == 10);
}

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