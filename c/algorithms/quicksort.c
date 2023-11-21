#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

void test_quick_sort();

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

void test_quick_sort()
{
    int test_arr1[5] = {5, 4, 3, 2, 1};
    int expected_arr1[5] = {1, 2, 3, 4, 5};
    quick_sort(test_arr1, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        assert(test_arr1[i] == expected_arr1[i]);
    }

    int test_arr2[5] = {3, 1, 4, 2, 5};
    int expected_arr2[5] = {1, 2, 3, 4, 5};
    quick_sort(test_arr2, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        assert(test_arr2[i] == expected_arr2[i]);
    }
}