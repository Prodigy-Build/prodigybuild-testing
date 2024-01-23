#include <stdio.h>
#include <stdlib.h>

// function to merge the sub-arrays
void merge(int a[], int low, int mid, int high) {
    int* b = (int*)malloc((high - low + 1) * sizeof(int)); // allocate memory for temporary array
    int i = low, j = mid + 1, k = 0; // initialize indices for merging

    // merge the sub-arrays
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    // copy the merged array back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = b[k];

    free(b); // free the memory for temporary array
}

// merge sort function
void mergesort(int a[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

// main function
int main() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int n = sizeof(a) / sizeof(a[0]);

    mergesort(a, 0, n - 1);

    printf("\n Sorted numbers are: ");

    // function to print the sorted array
    int k;
    for (k = 0; k < n; k++)
        printf("%d, ", a[k]);

    return 0;
}