#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void test_swap() {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    assert(a == 2);
    assert(b == 1);
}

void test_partition() {
    int a[] = {4, 3, 2, 1};
    int pivot_index = partition(a, 0, 3);
    assert(pivot_index == 3);
    assert(a[pivot_index] == 4);
}

void test_quick_sort() {
    int a[] = {4, 3, 2, 1};
    quick_sort(a, 0, 3);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 4);
}