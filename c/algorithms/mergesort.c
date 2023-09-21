#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// Function to merge the sub-arrays
void merge(int a[], int low, int mid , int high)
{
	int b[20]; 
	int i = low, j = mid + 1, k = low;

	// Iterate through the two halves of the array
	while(i <= mid && j <= high) {
		if(a[i] <= a[j]) {
		    b[k++] = a[i++];
		} else {
		   b[k++] = a[j++]; 
		}
	}

	// Finalize the sections of the array
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= high) {
		b[k++] = a[j++];
	}

	// Copy elements back into original array
	for (k = low; k <= high; k++) {
	        a[k] = b[k];
	}
}

// Merge sort function
void mergesort(int a[], int low, int high)
{
	// Base condition to exit recursion
	if(low >= high) {
	  return;
	}

	// Divide the array into two halves
	int mid = (low + high)/2;
	
	// Recursively sort the two halves
	mergesort(a, low, mid);
	mergesort(a, mid + 1, high);
	
	// Merge the sorted halves
	merge(a, low, mid, high);
}

// Main function
int main()
{
	// Array to be sorted
	int a[7] = {83, 20, 9, 50, 115, 61, 17}; 
	int n = 7; // Size of the array

	mergesort(a, 0, n - 1); // Call the merge sort function
	
	// Print the sorted array
	printf("\n Sorted numbers are: ");
	int k;
	for(k = 0; k < 7; k++) {
	    printf("%d, ", a[k]);
	}
	return 0;
}