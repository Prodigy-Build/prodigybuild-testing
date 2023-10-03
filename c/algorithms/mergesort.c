#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

// unit test for merge function
void test_merge()
{
    int a[] = {5, 10, 2, 7, 6, 3};
    int b[] = {2, 3, 5, 6, 7, 10};
    int size = sizeof(a) / sizeof(a[0]);
    merge(a, 0, size / 2, size - 1);
    for (int i = 0; i < size; i++)
        assert(a[i] == b[i]);
}

// unit test for mergesort function
void test_mergesort()
{
    int a[] = {83, 20, 9, 50, 115, 61, 17};
    int b[] = {9, 17, 20, 50, 61, 83, 115};
    int size = sizeof(a) / sizeof(a[0]);
    mergesort(a, 0, size - 1);
    for (int i = 0; i < size; i++)
        assert(a[i] == b[i]);
}

// main function
int main()
{
    test_merge();
    test_mergesort();

    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int n = 7;

    mergesort(a, 0, n - 1);

    printf("\n Sorted numbers are: ");

    // function to print the sorted array
    int k;
    for (k = 0; k < 7; k++)
        printf("%d, ", a[k]);
    return 0;
}