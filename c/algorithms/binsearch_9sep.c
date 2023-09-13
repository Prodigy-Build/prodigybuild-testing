#include <stdio.h>
#include "assert.h"

int binsearch(int yarr[], int num_elements, int element)
{
    int mid = num_elements / 2;
    int left = 0;
    int right = num_elements - 1;
    
    while(left <= right)
    {
        if(yarr[mid] < element)
            left = mid + 1;    
        else if(yarr[mid] == element) 
            return mid;
        else
            right = mid - 1;

        mid = (left + right)/2;
    }

    return -1; //if there is no match
}

void test_binsearch()
{
    int yarr[10] = {2, 3, 4, 10, 40, 55, 70, 80, 90, 100};
    assert(binsearch(yarr, 10, 2) == 0);
    assert(binsearch(yarr, 10, 100) == 9);
    assert(binsearch(yarr, 10, 40) == 4);
    assert(binsearch(yarr, 10, 101) == -1);
    
    printf("All test cases passed for binsearch");
}

int main()
{
    test_binsearch();
    return 0;
} 