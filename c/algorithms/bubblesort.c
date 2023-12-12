#include <stdio.h>
#include <assert.h>

// Function to perform bubble sort
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

// Function to perform unit tests
void test_bubble_sort() 
{
    int arr[] = {5, 8, 2, 1, 6};
    int sorted_arr[] = {1, 2, 5, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Test case 1: Test if bubble sort sorts the array correctly
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++) {
        assert(arr[i] == sorted_arr[i]);
    }

    // Test case 2: Test if bubble sort handles an empty array correctly
    int empty_arr[] = {};
    bubble_sort(empty_arr, 0);

    // Test case 3: Test if bubble sort handles an array of size 1 correctly
    int single_arr[] = {5};
    bubble_sort(single_arr, 1);
    assert(single_arr[0] == 5);

    // Add more test cases if needed
}

int main(void) 
{
    // Run unit tests
    test_bubble_sort();

    printf("All tests pass.\n");
    return 0;
}