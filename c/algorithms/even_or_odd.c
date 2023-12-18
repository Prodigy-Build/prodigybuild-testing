#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    int i;

    if (element == yarr[mid])
    {
        return mid;
    }

    for (i = 0; i < left; i++)
    {
        if (element == yarr[i])
        {
            return i;
        }
    }

    return -1;
}

void test_binsearch()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    printf("Searching for 9: %d\n", binsearch(arr, 9));    // Expected: 4
    printf("Searching for 13: %d\n", binsearch(arr, 13));  // Expected: 6
    printf("Searching for 2: %d\n", binsearch(arr, 2));    // Expected: -1
}

int main()
{
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;

    if (rem == 0)
    {
        printf("Even");
    }
    else
    {
        printf("Odd");
    }

    return 0;
}
