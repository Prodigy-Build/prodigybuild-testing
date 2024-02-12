#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        
        if(yarr[mid] == element)
        {
            return mid;
        }
        
        if(yarr[mid] < element)
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

int main(int argc, char *argv[])
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    int result = binsearch(array, 10, element);
    
    if(result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in array\n");
    }
    
    return 0;
}