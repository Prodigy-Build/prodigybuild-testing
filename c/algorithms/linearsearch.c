#include <stdio.h>
#include <stdbool.h>

// Function to perform a linear search
int linsearch(int *yarr, int val)
{
    // Get the number of elements in the array
    int size = sizeof(yarr) / sizeof(yarr[0]);

    // Loop through the array
    for(int i = 0; i < size; i++)
    {
        // Check if the current element matches the value
        if(yarr[i] == val)
        {
            return i; // Return the index of the element
        }
    }

    return -1; // Return -1 if the element is not found
}

// Test cases for linsearch function
void test_linsearch()
{
    int arr[] = {10, 20, 30, 40, 50};

    // Test case 1: Element present in the array
    int result = linsearch(arr, 30);
    printf("Test case 1: %d\n", result); // Expected output: 2

    // Test case 2: Element not present in the array
    result = linsearch(arr, 60);
    printf("Test case 2: %d\n", result); // Expected output: -1
}

int main()
{
    test_linsearch();

    return 0;
}