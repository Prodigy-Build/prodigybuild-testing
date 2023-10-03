#include <assert.h>

void test_bubble_sort(void) {
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    bubble_sort(arr, 10);
    assert(arr[0] == 0);
    assert(arr[1] == 1);
    assert(arr[2] == 2);
    assert(arr[3] == 3);
    assert(arr[4] == 4);
    assert(arr[5] == 6);
    assert(arr[6] == 7);
    assert(arr[7] == 8);
    assert(arr[8] == 9);
    assert(arr[9] == 10);
}

int main(void) 
{
    test_bubble_sort();
    return 0;
}