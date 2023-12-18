#include <stdio.h>
#include <stdbool.h>

int linsearch(int *yarr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }
    }
  
    return -1; // indicates that the element was not found
}

void test_linsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test case 1: element found
    int result = linsearch(arr, size, 3);
    printf("Element found at index: %d\n", result); // Expected output: 2

    // Test case 2: element not found
    result = linsearch(arr, size, 6);
    printf("Element not found: %d\n", result); // Expected output: -1
}

int main()
{
    test_linsearch();
    return 0;
}