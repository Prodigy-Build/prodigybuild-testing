#include <stdio.h>

int binsearch(int* yarr, int len, int element)
{
    int left = 0;
    int right = len - 1;
    int mid;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        
        if(yarr[mid] == element)
            return mid;
        
        if(yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main(int argc, char* argv[])
{
    int arr[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int element = argv[1];
    int result = binsearch(arr, len, element);
    
    if(result != -1)
        printf("%d\n", result);
    else
        printf("Element not in array\n");

    return 0;
}