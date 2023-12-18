#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void test_binsearch(); // Function declaration for test case

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
  
    if(element == yarr[mid])
        printf("%d", mid);

    for(int i = 0; i < left; i++)
    {
        if(element == yarr[i])
        {
            // Does this so that it doesn't print multiple times
            printf("%d", i);
        }
    }
}

int main()
{
    // Test case for binsearch function
    test_binsearch();
    
    return 0;
}

void test_binsearch()
{
    // Test case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int element1 = 3;
    binsearch(arr1, element1); // Expected output: 2
    
    // Test case 2
    int arr2[] = {10, 20, 30, 40, 50};
    int element2 = 20;
    binsearch(arr2, element2); // Expected output: 1
}