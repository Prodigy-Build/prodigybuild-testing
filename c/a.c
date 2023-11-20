#include <stdio.h>

#include <stdbool.h>  

int binsearch(int yarr[], int element)
{
    int left = 0;
    int right = 9;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (yarr[mid] == element)
            return mid;
        
        if (yarr[mid] < element)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int yarr[] = {2, 5, 8, 9, 11, 15, 18, 19, 20, 25};
    int length = sizeof(yarr) / sizeof(yarr[0]);
    
    int element = 18;
    int result = binsearch(yarr, element);
    
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);
    
    return 0;
}