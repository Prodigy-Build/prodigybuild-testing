#include <stdio.h>
#include <stdbool.h>

// Function to perform linear search
int linsearch(int *yarr, int val, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to run unit tests
void runTests()
{
    // Test case 1: Search for existing value
    int yarr1[] = {1, 2, 3, 4, 5};
    int val1 = 3;
    int size1 = sizeof(yarr1) / sizeof(yarr1[0]);
    int result1 = linsearch(yarr1, val1, size1);
    printf("Test case 1: %d\n", result1); // Output: 2

    // Test case 2: Search for non-existing value
    int yarr2[] = {1, 2, 3, 4, 5};
    int val2 = 6;
    int size2 = sizeof(yarr2) / sizeof(yarr2[0]);
    int result2 = linsearch(yarr2, val2, size2);
    printf("Test case 2: %d\n", result2); // Output: -1

    // Test case 3: Search for value in empty array
    int yarr3[] = {};
    int val3 = 1;
    int size3 = sizeof(yarr3) / sizeof(yarr3[0]);
    int result3 = linsearch(yarr3, val3, size3);
    printf("Test case 3: %d\n", result3); // Output: -1
}

int main()
{
    runTests(); // Run the unit tests
    return 0;
}