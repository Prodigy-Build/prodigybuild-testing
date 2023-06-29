



// quicksort_123.c
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Unit test cases
#include <assert.h>

void test_swap() {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    assert(a == 2);
    assert(b == 1);
}

void test_partition() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pi = partition(arr, 0, n-1);
    assert(pi == 3);
    assert(arr[pi] == 9);
}

void test_quickSort() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    assert(arr[0] == 1);
    assert(arr[1] == 5);
    assert(arr[2] == 7);
    assert(arr[3] == 8);
    assert(arr[4] == 9);
    assert(arr[5] == 10);
}

int main()
{
    test_swap();
    test_partition();
    test_quickSort();
    return 0;
}