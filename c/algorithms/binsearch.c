#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    
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
};

void test_binsearch() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binsearch(arr1, 5) == 4);
    assert(binsearch(arr1, 11) == -1);
    assert(binsearch(arr1, 0) == -1);

    int arr2[1] = {1};
    assert(binsearch(arr2, 1) == 0);
    assert(binsearch(arr2, 0) == -1);
}

int main(int argc, int argv[])
{
    test_binsearch();
    printf("All tests passed.\n");
    return 0;
}