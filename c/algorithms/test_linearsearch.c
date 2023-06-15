

#include <stdio.h>
#include <assert.h>

/* Linear Search Test */

int linsearch(int *arr, int val);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int val = 3;
    int expected = 2;

    int result = linsearch(arr, val);

    assert(result == expected);

    printf("Linear Search Test Passed!\n");
}

