#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int size, int element) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (yarr[mid] == element)
            return mid;
        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void test() {
    int yarr[] = {2, 4, 7, 9, 10, 13, 15, 17, 21, 28};
    assert(binsearch(yarr, 10, 10) == 4); // test with an element that exists
    assert(binsearch(yarr, 10, 1) == -1);  // test with an element that doesn't exist
}

int main() {
    test();
    return 0;
}
