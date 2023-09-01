#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[], int yarrLength, int element)
{
    int left = 0;
    int right = yarrLength - 1;
    int mid;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        
        if(yarr[mid] == element)
            return mid;
            
        if (yarr[mid] < element)
            left = mid + 1;
            
        else
            right = mid - 1;
    }
    
    return -1;
};

int main(void)
{
    int yarr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int yarrLength = sizeof(yarr) / sizeof(yarr[0]);
    int element = 60;
    
    int index = binsearch(yarr, yarrLength, element);
    
    assert(index == 5);
    
    return 0;
}

