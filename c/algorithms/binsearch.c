#include <stdio.h>

int binsearch(int arr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == element)
        {
            return mid;
        }
        
        if (arr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 12;
    
    int result = binsearch(arr, size, element);
    
    printf("Element found at index: %d\n", result);
    
    return 0;
}