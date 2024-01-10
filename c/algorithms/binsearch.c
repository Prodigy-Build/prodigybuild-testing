#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid;
    int left = 0;
    int right = 9;
    int i;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        
        if(yarr[mid] == element)
            return mid;
            
        if(yarr[mid] < element)
            left = mid + 1;

        if(yarr[mid] > element)
            right = mid - 1;
    }
    return -1;
}

void testCases() 
{
    int testArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binsearch(testArray, 3) == 2);
    assert(binsearch(testArray, 5) == 4);
    assert(binsearch(testArray, 11) == -1);
}

int main()
{
    testCases();
    return 0;
}