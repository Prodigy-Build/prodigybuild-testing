#include <assert.h>
#include <stdbool.h>

void test_partition() {
    int a[] = {5, 2, 9, 3, 6, 0};
    int p = partition(a, 0, 6);
    assert(p == 3);
    assert(a[p] == 5);
}

void test_quick_sort() {
    int a[] = {5, 2, 9, 3, 6, 0};
    quick_sort(a, 0, 6);
    bool is_sorted = true;
    for (int i = 0; i < 6 - 1; i++) {
        if (a[i] > a[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    assert(is_sorted);
}

void test_swap() {
    int a = 5;
    int b = 2;
    swap(&a, &b);
    assert(a == 2);
    assert(b == 5);
}

int main() {
    test_partition();
    test_quick_sort();
    test_swap();
    printf("All tests passed successfully.\n");
    return 0;
}