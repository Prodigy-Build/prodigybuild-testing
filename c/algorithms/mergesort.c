#include <stdio.h>

void test_merge() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    merge(a, 0, 2, 4);
    // a should be {20, 9, 50, 83, 115, 61, 17}
}

void test_mergesort() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    mergesort(a, 0, 6);
    // a should be {9, 17, 20, 50, 61, 83, 115}
}

int main() {
    test_merge();
    test_mergesort();
    return 0;
}