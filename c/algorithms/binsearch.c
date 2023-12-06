#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int left = 0;
    int right = 10;
    int mid;
    int i;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (yarr[mid] == element)
            return mid;
        
        if (yarr[mid] < element)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    return -1;
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    
    int result = binsearch(yarr, element);
    
    printf("%d", result);
}