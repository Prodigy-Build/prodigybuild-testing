#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int low = 0;
    int high = 9;
    int mid;

    while (low <= high) 
    {
        mid = low + (high - low) / 2;
        if (yarr[mid] == element)
        {
            return mid;
        }
        else if (yarr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[10] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 100};
    int element = 34;
    int found = binsearch(arr, element);

    if(found == -1) 
    {
        printf("Element not present in the array.\n");
    } 
    else 
    {
        printf("Element found at index: %d\n", found);
    }

    element = 75;
    found = binsearch(arr, element);

    if(found == -1) 
    {
        printf("Element not present in the array.\n");
    } 
    else 
    {
        printf("Element found at index: %d\n", found);
    }

    return 0;
}
