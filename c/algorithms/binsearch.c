#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / 2 - 1;
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    int i;
    
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(yarr[mid] == element) {
            return mid;
        }
        if (yarr[mid] < element) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;
};

void test_binsearch()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(binsearch(arr,1)==0);
    assert(binsearch(arr,5)==4);
    assert(binsearch(arr,10)==9);
    assert(binsearch(arr,11)==-1);
    printf("All test cases passed for binsearch.\n");
}

int main(int argc, char *argv[])
{
    test_binsearch();
    return 0;
}