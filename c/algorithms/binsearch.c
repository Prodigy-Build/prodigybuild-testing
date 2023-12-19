#include <stdio.h>

void test_binsearch()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr3[] = {-5, 0, 5, 10, 15, 20, 25, 30, 35, 40};
    int arr4[] = {0, 0, 0, 0, 0};
    int arr5[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    
    if(binsearch(arr1, 3) != 2)
    {
        printf("Test case 1 failed\n");
    }
    
    if(binsearch(arr2, 30) != -1)
    {
        printf("Test case 2 failed\n");
    }
    
    if(binsearch(arr3, 20) != 5)
    {
        printf("Test case 3 failed\n");
    }
    
    if(binsearch(arr4, 0) != -1)
    {
        printf("Test case 4 failed\n");
    }
    
    if(binsearch(arr5, 15) != -1)
    {
        printf("Test case 5 failed\n");
    }
}

int binsearch(int arr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        if(arr[mid] == element)
        {
            return mid;
        }
        
        if(arr[mid] < element)
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
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 3;
    
    int result = binsearch(arr, size, element);
    
    if(result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }
    
    test_binsearch();
    
    return 0;
}