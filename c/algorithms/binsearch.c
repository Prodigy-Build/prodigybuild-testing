#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / 2;
    int left = 0;
    int right = sizeof(yarr) - 1;
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

void test_binsearch() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binsearch(yarr, 5) == 4);
    assert(binsearch(yarr, 11) == -1);
    assert(binsearch(yarr, -1) == -1);
    printf("All test cases passed successfully\n");
}

int main(int argc, int argv[])
{
    test_binsearch();
    return 0;
}