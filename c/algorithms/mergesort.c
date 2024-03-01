#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    merge(a, 0, 2, 6);
    for (int i = 0; i < 7; i++)
    {
        if (a[i] != expected[i])
        {
            printf("Merge test failed\n");
            return;
        }
    }
    printf("Merge test passed\n");
}

// unit test for mergesort function
void test_mergesort()
{
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    mergesort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        if (a[i] != expected[i])
        {
            printf("Mergesort test failed\n");
            return;
        }
    }
    printf("Mergesort test passed\n");
}

// main function
int main()
{
    test_merge();
    test_mergesort();
    return 0;
}