#include <stdio.h>

// function to merge the sub-arrays
void merge(int a[], int low, int mid, int high) {
    int b[20]; //same size of a[]
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
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
void mergesort(int a[], int low, int high) {
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

// function to print the sorted array
void printSortedArray(int a[], int n) {
    int k;
    for (k = 0; k < n; k++)
        printf("%d, ", a[k]);
    printf("\n");
}

// unit tests
void testMergeSort() {
    int a1[] = {83, 20, 9, 50, 115, 61, 17};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    mergesort(a1, 0, n1 - 1);
    printSortedArray(a1, n1);

    int a2[] = {3, 1, 7, 4, 2, 9, 5};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    mergesort(a2, 0, n2 - 1);
    printSortedArray(a2, n2);

    int a3[] = {12, 10, 8, 6, 4, 2, 0};
    int n3 = sizeof(a3) / sizeof(a3[0]);
    mergesort(a3, 0, n3 - 1);
    printSortedArray(a3, n3);
}

int main() {
    // run unit tests
    testMergeSort();

    return 0;
}