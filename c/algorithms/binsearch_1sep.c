```c
#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(yarr[mid] == element)
        {
            return mid;
        }
        else if(yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
};

void test_binsearch()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    assert(binsearch(arr1, 5, 7) == 3);
    assert(binsearch(arr1, 5, 10) == -1);

    int arr2[5] = {-100, 0, 100, 200, 300};
    assert(binsearch(arr2, 5, 200) == 3);
    assert(binsearch(arr2, 5, 50) == -1);
}

int main()
{
    test_binsearch();
    return 0;
}
```
