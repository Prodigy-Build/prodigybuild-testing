#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[], int size, int element) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
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

// Unit Test Cases
int main() {
    // Test Case 1
    int yarr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(yarr1) / sizeof(yarr1[0]);
    int element1 = 2;
    int expected1 = 1;
    int result1 = binsearch(yarr1, size1, element1);
    printf("Test Case 1: %d\n", result1 == expected1);

    // Test Case 2
    int yarr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(yarr2) / sizeof(yarr2[0]);
    int element2 = 6;
    int expected2 = -1;
    int result2 = binsearch(yarr2, size2, element2);
    printf("Test Case 2: %d\n", result2 == expected2);

    // Test Case 3
    int yarr3[] = {10, 20, 30, 40, 50};
    int size3 = sizeof(yarr3) / sizeof(yarr3[0]);
    int element3 = 30;
    int expected3 = 2;
    int result3 = binsearch(yarr3, size3, element3);
    printf("Test Case 3: %d\n", result3 == expected3);

    return 0;
}