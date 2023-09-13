#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid, left = 0;
    int right = size - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (yarr[mid] == element)
        {
            return mid;
        }
        if (yarr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; 
}

int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    int size = sizeof(array) / sizeof(array[0]);
    int result = binsearch(array, size, element);

    printf("Test case 1: Looking for 3 in the array\n");
    assert(binsearch(array, size, 3) == 2);
    printf("Test case 1 passed.\n");
  
    printf("Test case 2: Looking for 5 in the array\n");
    assert(binsearch(array, size, 5) == 4);
    printf("Test case 2 passed.\n");

    printf("Test case 3: Looking for 11 in the array\n");
    assert(binsearch(array, size, 11) == -1);
    printf("Test case 3 passed.\n");

    printf("Index of %d in array is %d\n", element, result);
    return 0;
}

