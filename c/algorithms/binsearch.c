#include <stdio.h>

void test_binsearch()
{
    int test_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: element is in the middle of the array
    int result = binsearch(test_arr, 5);
    printf("Test Case 1: %d\n", result);
    
    // Test case 2: element is not in the array
    result = binsearch(test_arr, 15);
    printf("Test Case 2: %d\n", result);
    
    // Test case 3: element is in the left half of the array
    result = binsearch(test_arr, 2);
    printf("Test Case 3: %d\n", result);
    
    // Test case 4: element is in the right half of the array
    result = binsearch(test_arr, 9);
    printf("Test Case 4: %d\n", result);
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = 10 - left;
    int i;
    
    if(element == yarr[mid])
    {
        printf("%d\n", yarr[mid]);
        return mid;
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", yarr[i]);
                return i;
            }
        }
    }
    
    return -1; // element not found
}

int main(int argc, char* argv[])
{
    test_binsearch();
    
    return 0;
}