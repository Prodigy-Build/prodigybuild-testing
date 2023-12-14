#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// function to merge the sub-arrays
void merge(int a[], int low, int mid, int high)
{
    int b[20]; //same size of a[]
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++]; //copying the elements
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

// merge sort function
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

// unit tests
void test_merge()
{
    int a1[5] = {1, 3, 5, 2, 4};
    merge(a1, 0, 2, 4);
    assert(a1[0] == 1);
    assert(a1[1] == 2);
    assert(a1[2] == 3);
    assert(a1[3] == 4);
    assert(a1[4] == 5);

    int a2[7] = {7, 5, 3, 1, 8, 6, 4};
    merge(a2, 0, 3, 6);
    assert(a2[0] == 1);
    assert(a2[1] == 3);
    assert(a2[2] == 4);
    assert(a2[3] == 5);
    assert(a2[4] == 6);
    assert(a2[5] == 7);
    assert(a2[6] == 8);
}

void test_mergesort()
{
    int a1[5] = {5, 3, 1, 4, 2};
    mergesort(a1, 0, 4);
    assert(a1[0] == 1);
    assert(a1[1] == 2);
    assert(a1[2] == 3);
    assert(a1[3] == 4);
    assert(a1[4] == 5);

    int a2[7] = {83, 20, 9, 50, 115, 61, 17};
    mergesort(a2, 0, 6);
    assert(a2[0] == 9);
    assert(a2[1] == 17);
    assert(a2[2] == 20);
    assert(a2[3] == 50);
    assert(a2[4] == 61);
    assert(a2[5] == 83);
    assert(a2[6] == 115);
}

int main()
{
    test_merge();
    test_mergesort();

    printf("All tests passed!");

    return 0;
}