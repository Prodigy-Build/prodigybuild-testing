```c
#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (yarr[mid] == element)
            return mid;

        if (yarr[mid] < element)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

void test_binsearch() {
    int yarr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    if(binsearch(yarr, 10, 23) != 5)
        printf("Test 1 failed");

    if(binsearch(yarr, 10, 8) != 2)
        printf("Test 2 failed");

    if(binsearch(yarr, 10, 91) != 9)
        printf("Test 3 failed");

    if(binsearch(yarr, 10, 1) != -1)
        printf("Test 4 failed");

    printf("All tests passed");
}

int main(int argc, char* argv[])
{
    test_binsearch();

    return 0;
}
```