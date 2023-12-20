#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int left = 0;
    int right = 9;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (yarr[mid] == element) {
            return mid;
        }
        else if (yarr[mid] < element) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    
    int result = binsearch(arr, element);
    printf("Element found at index: %d\n", result);
    
    return 0;
}