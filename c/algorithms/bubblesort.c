#include <stdio.h>
#include "cunit.h"

void bubble_sort(int *array, int len) 
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void test_bubble_sort()
{
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int sorted_arr[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    bubble_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        CU_ASSERT_EQUAL(arr[i], sorted_arr[i]);
    }
}

int main(void) 
{
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("BubbleSortSuite", NULL, NULL);
    CU_add_test(suite, "test_bubble_sort", test_bubble_sort);

    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}