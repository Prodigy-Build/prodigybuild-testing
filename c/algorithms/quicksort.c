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
    int a[5] = {3, 1, 5, 4, 2};
    int l = 0;
    int h = 4;

    int p = partition(a, l, h);

    assert(p == 2);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 5);
    assert(a[4] == 4);
}

void test_quick_sort()
{
    int a[5] = {3, 1, 5, 4, 2};
    int l = 0;
    int h = 4;

    quick_sort(a, l, h);

    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 4);
    assert(a[4] == 5);
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