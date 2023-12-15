#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (yarr[mid] == element)
        {
            return mid;
        }
        
        if (yarr[mid] < element)
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
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    int element = 7;
    int result = binsearch(yarr, size, element);
    printf("Element %d found at index: %d\n", element, result);
    
    element = 15;
    result = binsearch(yarr, size, element);
    printf("Element %d found at index: %d\n", element, result);
    
    return 0;
}
