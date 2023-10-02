#include <stdio.h>

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    
    // Test case 1: element is in the middle of the array
    int result = binsearch(arr, 3);
    printf("Test case 1: %d\n", result);
    
    // Test case 2: element is not found
    result = binsearch(arr, 6);
    printf("Test case 2: %d\n", result);
    
    // Test case 3: element is at the beginning of the array
    result = binsearch(arr, 1);
    printf("Test case 3: %d\n", result);
    
    // Test case 4: element is at the end of the array
    result = binsearch(arr, 5);
    printf("Test case 4: %d\n", result);
}

int binsearch(int arr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    extern int i;
    
    if (element == arr[mid])
    {
        printf("%d\n", arr[mid]);
        return mid;
    }
    
    if (element != arr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == arr[i])
            {
                printf("%d\n", arr[i]);
                return i;
            }
        }
    }
    
    return -1;
}

int main()
{
    test_binsearch();
    
    return 0;
}