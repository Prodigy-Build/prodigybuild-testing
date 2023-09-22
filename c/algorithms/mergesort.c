#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// Function to merge the sub-arrays
void merge(int a[], int low, int mid, int high) {
    int b[20]; // Temporary array

    // Pointers for a[low..mid] and a[mid+1..high]
    int i = low;
    int j = mid + 1;
    int k = low;

    // Merge the two halves
    while (i <= mid && j <= high) {
        // Choose minimum between two
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    // If any elements are left in first half
    while (i <= mid)
        b[k++] = a[i++];

    // If any elements are left in second half
    while (j <= high)
        b[k++] = a[j++];

    // Copy temporary array back into original array
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

// Merge sort function
void mergesort(int a[], int low, int high) {
    int mid;

    // Base case (single element)
    if (low >= high)
        return;

    // Find mid point
    mid = (low + high) / 2;

    // Recursively split and sort
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);

    // Merge results
    merge(a, low, mid, high);
}

// Main function
int main() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17}; // Input array
    int n = 7; // Size of array

    // Perform merge sort
    mergesort(a, 0, n-1);

    printf("\nSorted numbers are: ");

    // Function to print the sorted array
    for (int k = 0; k < 7; k++)
        printf("%d ", a[k]);

    return 0;
}