#include <stdio.h>

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

// unit test cases for merge function
void test_merge()
{
    int a[] = {20, 9, 50, 83, 17, 61, 115};
    int b[] = {9, 17, 20, 50, 61, 83, 115};
    int i;
    merge(a, 0, 2, 6);
    for (i = 0; i < 7; i++)
    {
        if (a[i] != b[i])
        {
            printf("Merge Test Case Failed");
            return;
        }
    }
    printf("Merge Test Case Passed");
}

// unit test cases for mergesort function
void test_mergesort()
{
    int a[] = {83, 20, 9, 50, 115, 61, 17};
    int b[] = {9, 17, 20, 50, 61, 83, 115};
    int i;
    mergesort(a, 0, 6);
    for (i = 0; i < 7; i++)
    {
        if (a[i] != b[i])
        {
            printf("Merge Sort Test Case Failed");
            return;
        }
    }
    printf("Merge Sort Test Case Passed");
}

int main()
{
    // run test cases
    test_merge();
    test_mergesort();

    return 0;
}