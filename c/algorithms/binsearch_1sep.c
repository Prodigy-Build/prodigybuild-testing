#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
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
    int yarr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    assert(binsearch(yarr, 10, 5) == 2);
    assert(binsearch(yarr, 10, 6) == -1);
    assert(binsearch(yarr, 10, 1) == 0);
    assert(binsearch(yarr, 10, 19) == 9);
    assert(binsearch(yarr, 10, 0) == -1);
}

int main()
{
    test_binsearch();
    return 0;
}

