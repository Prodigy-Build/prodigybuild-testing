#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        if (element == yarr[mid])
        {
            return mid;
        }
            
        if (element < yarr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return -1;
}

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    assert(binsearch(arr, size, 1) == 0);
    assert(binsearch(arr, size, 5) == 4);
    assert(binsearch(arr, size, 10) == 9);
    assert(binsearch(arr, size, -1) == -1);
    assert(binsearch(arr, size, 11) == -1);
}

int main()
{
    test_binsearch();
    return 0;
}