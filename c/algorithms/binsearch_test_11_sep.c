#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int low = 0;
    int high = 9;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(yarr[mid] == element)
        {
            return mid;
        }

        if(yarr[mid] < element)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
};

int main()
{
    int yarr[10] = {1,3,4,6,7,9,11,13,14,16};
    int element = 9;
    int result = binsearch(yarr, element);

    if(result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");

    element = 5;
    result = binsearch(yarr, element);

    if(result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");

    return 0;
}
