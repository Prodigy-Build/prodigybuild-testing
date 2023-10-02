#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        
        if(yarr[mid] == element)
            return mid;
        
        if(yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    assert(binsearch(arr, size, 1) == 0);
    assert(binsearch(arr, size, 2) == 1);
    assert(binsearch(arr, size, 3) == 2);
    assert(binsearch(arr, size, 4) == 3);
    assert(binsearch(arr, size, 5) == 4);
    assert(binsearch(arr, size, 6) == -1);   
}

int main()
{
    test_binsearch();
    return 0;
}