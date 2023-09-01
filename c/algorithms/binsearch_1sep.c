#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int low = 0, high = 9;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (yarr[mid] == element)
           return mid;
        if (yarr[mid] < element)
           low = mid + 1;
        else
           high = mid - 1;
    }
    return -1;  
};

int main(void)
{
    int yarr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    // Testing binsearch function with different test cases
    printf("Test Case 1: %d\n", binsearch(yarr,2));  // Expected output: 1 (As 2 is present at index 1)
    printf("Test Case 2: %d\n", binsearch(yarr,5));  // Expected output: 4 (As 5 is present at index 4)
    printf("Test Case 3: %d\n", binsearch(yarr,12)); // Expected output: -1 (As 12 is not present in the array) 

    return 0;
}
