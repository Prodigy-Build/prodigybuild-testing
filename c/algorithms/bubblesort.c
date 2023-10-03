#include <assert.h>

void test_bubble_sort() {
    int arr1[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    bubble_sort(arr1, len1);

    int sorted1[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    for (int i = 0; i < len1; i++)
        assert(arr1[i] == sorted1[i]);

    int arr2[] = {5};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    bubble_sort(arr2, len2);

    int sorted2[] = {5};
    for (int i = 0; i < len2; i++)
        assert(arr2[i] == sorted2[i]);

    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    bubble_sort(arr3, len3);

    int sorted3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < len3; i++)
        assert(arr3[i] == sorted3[i]);

    int arr4[] = {-1, 4, 0, -5, 2};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);
    bubble_sort(arr4, len4);

    int sorted4[] = {-5, -1, 0, 2, 4};
    for (int i = 0; i < len4; i++)
        assert(arr4[i] == sorted4[i]);
}

int main(void) {
    test_bubble_sort();
    return 0;
}