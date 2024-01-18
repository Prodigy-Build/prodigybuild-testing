#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// function to merge the subarrays
void merge(int a[],int low,int mid ,int high) {
    int b[20];
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high) {
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i<=mid)
        b[k++] = a[i++];
    while (j<=high)
        b[k++] = a[j++];
    for (k=low; k<=high; k++)
        a[k] = b[k];
}

// merge sort function
void mergesort(int a[],int low,int high) {
    if(low < high) {
        int mid = low + (high - low)/2; //This will avoid overflow for large values of low and high
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

// main fucntion
int main() {
    int a[] = {83, 20, 9, 50, 115, 61, 17};
    int n = sizeof(a)/sizeof(a[0]);

    mergesort(a, 0, n-1);
    
    printf("\n Sorted numbers are: ");

    // function to print the sorted array
    int k;
    for(k = 0; k < n; k++)
        printf("%d, ",a[k]);
    return 0;
}