#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_swap();
void test_partition();
void test_quick_sort();

// Unit tests
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

void test_swap()
{
    int a = 3;
    int b = 4;
    swap(&a, &b);
    assert(a == 4 && b == 3);
}

void test_partition()
{
    int a[] = {4, 2, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int p = partition(a, 0, n - 1);
    assert(p == 2 && a[p] == 3);
}

void test_quick_sort()
{
    int a[] = {4, 2, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, 0, n - 1);
    assert(a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4);
}