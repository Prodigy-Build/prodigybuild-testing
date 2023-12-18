#include <stdio.h>

// Unit test cases
void test_binsearch() {
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 3;
    int result = binsearch(yarr, element);
    printf("Result: %d\n", result); // Expected output: 2
    
    element = 8;
    result = binsearch(yarr, element);
    printf("Result: %d\n", result); // Expected output: 7
    
    element = 12;
    result = binsearch(yarr, element);
    printf("Result: %d\n", result); // Expected output: -1
    
    // Add more test cases as needed...
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    extern int i;
    
    if(element == yarr[mid])
        return mid;
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                return i;
            }
        }
    }
    
    return -1; // Element not found
}

int main(int argc, int *argv[])
{
    test_binsearch();
    return 0;
}