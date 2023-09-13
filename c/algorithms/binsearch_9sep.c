#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int num, int element)
{
    int left = 0;
    int right = num - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (yarr[mid] == element)  
            return mid;  
        if (yarr[mid] < element)  
            left = mid + 1;  
        else
            right = mid - 1; 
    }
    return -1;  
};

void test_binsearch()
{
    int arr1[6] = {2, 3, 4, 10, 40, 50};
    int arr2[5] = {1, 2, 3, 4, 5};
    assert(binsearch(arr1, 6, 10) == 3);
    assert(binsearch(arr2, 5, 1) == 0);
    assert(binsearch(arr2, 5, 6) == -1);
}

int main()
{
    test_binsearch();
    return 0;
}
