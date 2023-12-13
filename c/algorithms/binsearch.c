#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (yarr[mid] == element) {
            return mid;
        }

        if (yarr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

void test_binsearch()
{
    int yarr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    
    // Test cases
    printf("Searching for 8: %d\n", binsearch(yarr, size, 8)); // Expected output: 3
    printf("Searching for 20: %d\n", binsearch(yarr, size, 20)); // Expected output: 9
    printf("Searching for 1: %d\n", binsearch(yarr, size, 1)); // Expected output: -1
    printf("Searching for 15: %d\n", binsearch(yarr, size, 15)); // Expected output: -1
}

int main(int argc, char *argv[])
{
    test_binsearch();

    return 0;
}