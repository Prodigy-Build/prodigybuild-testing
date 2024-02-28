#include <stdio.h>
#include <stdbool.h>

// Function to perform linear search
bool linsearch(int *yarr, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return true;
        }    
    }
    return false;
}

// Unit test cases
void test_linsearch()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int val1 = 3;
    if(linsearch(arr1, size1, val1))
    {
        printf("Test case 1 passed\n");
    }
    else
    {
        printf("Test case 1 failed\n");
    }
    
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int val2 = 25;
    if(!linsearch(arr2, size2, val2))
    {
        printf("Test case 2 passed\n");
    }
    else
    {
        printf("Test case 2 failed\n");
    }
    
    int arr3[] = {100, 200, 300, 400, 500};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int val3 = 100;
    if(linsearch(arr3, size3, val3))
    {
        printf("Test case 3 passed\n");
    }
    else
    {
        printf("Test case 3 failed\n");
    }
}

int main()
{
    test_linsearch();
    return 0;
}