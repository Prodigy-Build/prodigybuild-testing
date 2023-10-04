'''
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

// unit test cases
void test_swap() {
    int a = 1, b = 2;
    swap(&a, &b);
    assert(a == 2 && b == 1);
    
    int c = 0, d = 0;
    swap(&c, &d);
    assert(c == 0 && d == 0);
}

void test_partition() {
    int arr1[] = {4, 3, 2, 1};
    int p1 = partition(arr1, 0, 3);
    for (int i = 0; i < p1; i++) {
        assert(arr1[i] <= arr1[p1]);
    }
    for (int i = p1 + 1; i <= 3; i++) {
        assert(arr1[i] > arr1[p1]);
    }
    
    int arr2[] = {1, 2, 3, 4};
    int p2 = partition(arr2, 0, 3);
    for (int i = 0; i < p2; i++) {
        assert(arr2[i] <= arr2[p2]);
    }
    for (int i = p2 + 1; i <= 3; i++) {
        assert(arr2[i] > arr2[p2]);
    }
    
    int arr3[] = {1, 2, 3, 3, 2, 1};
    int p3 = partition(arr3, 0, 5);
    for (int i = 0; i < p3; i++) {
        assert(arr3[i] <= arr3[p3]);
    }
    for (int i = p3 + 1; i <= 5; i++) {
        assert(arr3[i] > arr3[p3]);
    }
}

void test_quick_sort() {
    int arr1[] = {4, 3, 2, 1};
    quick_sort(arr1, 0, 3);
    for (int i = 0; i <= 3; i++) {
        assert(arr1[i] == i + 1);
    }
    
    int arr2[] = {1, 2, 3, 4};
    quick_sort(arr2, 0, 3);
    for (int i = 0; i <= 3; i++) {
        assert(arr2[i] == i + 1);
    }
    
    int arr3[] = {1, 2, 3, 3, 2, 1};
    quick_sort(arr3, 0, 5);
    for (int i = 0; i <= 5; i++) {
        assert(arr3[i] == i + 1);
    }
    
    int arr4[] = {5};
    quick_sort(arr4, 0, 0);
    assert(arr4[0] == 5);
    
    int arr5[] = {};
    quick_sort(arr5, 0, -1);
    // no assertion needed, empty array
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

'''