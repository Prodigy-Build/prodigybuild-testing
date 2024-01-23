#include <stdio.h>

void insertionSort(int arr[], int n) 
{ 
    int i, element, j; 
    for (i = 1; i < n; i++) 
    { 
        element = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > element) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = element; 
    } 
} 

int main()
{
    int arr[] = {5, 6, 4, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n); 

    return 0;
}