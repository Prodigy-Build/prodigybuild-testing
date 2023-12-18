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
    assert(a == 10 && b == 5);
}

void test_partition()
{
    int a[] = {5, 1, 8, 3, 9};
    int p = partition(a, 0, 4);

    assert(p == 3);
    assert(a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 9 && a[4] == 8);
}

void test_quick_sort()
{
    int a[] = {5, 1, 8, 3, 9};
    quick_sort(a, 0, 4);

    assert(a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 8 && a[4] == 9);
}

int main()
{
    // Call the unit test functions
    test_swap();
    test_partition();
    test_quick_sort();
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
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