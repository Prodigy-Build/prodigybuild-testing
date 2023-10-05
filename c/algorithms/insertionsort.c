```c
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    
    insertionSort(unsorted, n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", unsorted[i]);
    }
    
    return 0;
}
```