#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if(yarr[mid] == element)
            return mid;

        if(yarr[mid] < element)
            start = mid + 1;
        else
            end = mid -1;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./program array element\n");
        return 1;
    }
    
    int arr[] = {argv[1]}; // This should be replaced with actual number array, argv[1] is just an example
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = atoi(argv[2]); // This is just an example, convert to int

    int result = binsearch(arr, size, element);
    printf("Element found at index: %d\n", result);
    
    return 0;
}