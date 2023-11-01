```c
#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (yarr[mid] == element)
        {
            return mid;
        }
        else if (yarr[mid] < element)
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

void test_binsearch()
{
    int yarr[] = {2, 4, 6, 8, 10};
    int size = sizeof(yarr) / sizeof(yarr[0]);

    // Test cases
    printf("Searching for 4 in yarr: %d\n", binsearch(yarr, size, 4)); // Expected output: 1
    printf("Searching for 8 in yarr: %d\n", binsearch(yarr, size, 8)); // Expected output: 3
    printf("Searching for 7 in yarr: %d\n", binsearch(yarr, size, 7)); // Expected output: -1
}

int main()
{
    test_binsearch();

    return 0;
}
```