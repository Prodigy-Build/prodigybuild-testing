#include <stdio.h>
#include <assert.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void test_insertionSort()
{
    int test1[] = {5, 6, 4, 3, 9};
    int test2[] = {1, 2, 3, 4, 5};
    int test3[] = {9, 8, 7, 6, 5};
    int test4[] = {1};
    int test5[] = {};

    insertionSort(test1, sizeof(test1) / sizeof(test1[0]));
    insertionSort(test2, sizeof(test2) / sizeof(test2[0]));
    insertionSort(test3, sizeof(test3) / sizeof(test3[0]));
    insertionSort(test4, sizeof(test4) / sizeof(test4[0]));
    insertionSort(test5, sizeof(test5) / sizeof(test5[0]));

    assert(test1[0] == 3 && test1[1] == 4 && test1[2] == 5 && test1[3] == 6 && test1[4] == 9);
    assert(test2[0] == 1 && test2[1] == 2 && test2[2] == 3 && test2[3] == 4 && test2[4] == 5);
    assert(test3[0] == 5 && test3[1] == 6 && test3[2] == 7 && test3[3] == 8 && test3[4] == 9);
    assert(test4[0] == 1);
    assert(sizeof(test5) == 0);
}

int main()
{
    test_insertionSort();
    printf("All test cases pass\n");
    return 0;
}