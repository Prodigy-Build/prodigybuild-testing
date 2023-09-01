#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if(yarr[mid] == element)
            return mid;
        if(yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
};

void test_cases()
{
    int arr1[3] = {1, 2, 3};
    assert(binsearch(arr1, 3, 2) == 1);

    int arr2[5] = {1, 3, 5, 7, 9};
    assert(binsearch(arr2, 5, 5) == 2);
    assert(binsearch(arr2, 5, 4) == -1);

    printf("All test cases passed.");
}

int main()
{
    test_cases();
    return 0;
}

