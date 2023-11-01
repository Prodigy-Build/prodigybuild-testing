#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
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

void test_binsearch()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 12;
    
    assert(binsearch(arr, size, element) == 5);
    
    element = 7;
    assert(binsearch(arr, size, element) == -1);
    
    element = 2;
    assert(binsearch(arr, size, element) == 0);
    
    element = 20;
    assert(binsearch(arr, size, element) == 9);
}

int main()
{
    test_binsearch();
    return 0;
}