#include <assert.h>

int binsearch(int yarr[], int size, int element) {
    int mid = size / 2;
    int left = mid;
    int right = size - 1;
    int i;

    if (element == yarr[mid]) {
        return mid;
    }
    else if (element > yarr[mid]) {
        left = mid + 1;
    }
    else {
        right = mid - 1;
    }

    for (i = left; i <= right; i++) {
        if (element == yarr[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int yarr[] = {1, 2, 3, 4, 5};
    int size = sizeof(yarr) / sizeof(yarr[0]);

    assert(binsearch(yarr, size, 3) == 2);
    assert(binsearch(yarr, size, 6) == -1);
    assert(binsearch(yarr, size, 1) == 0);
    assert(binsearch(yarr, size, 5) == 4);

    return 0;
}