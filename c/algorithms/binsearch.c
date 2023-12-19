#include <stdio.h>

void test_binsearch()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Test for element in the middle of the array
    int result1 = binsearch(arr, 11);
    printf("Result1: %d\n", result1);
    
    // Test for element in the left half of the array
    int result2 = binsearch(arr, 5);
    printf("Result2: %d\n", result2);
    
    // Test for element in the right half of the array
    int result3 = binsearch(arr, 17);
    printf("Result3: %d\n", result3);
    
    // Test for element not in the array
    int result4 = binsearch(arr, 4);
    printf("Result4: %d\n", result4);
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid - 1;
    int right = mid + 1;
    extern int i;
    
    if (element == yarr[mid])
    {
        return mid;
    }
    
    if (element != yarr[right] && element != yarr[left])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                return i;
            }
        }
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    test_binsearch();
    return 0;
}