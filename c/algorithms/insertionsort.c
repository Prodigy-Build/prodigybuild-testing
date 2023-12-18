#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    
    if(element == yarr[mid])
    {
        printf("%d\n", element);
    }
    
    for(int i = 0; i < left; i++)
    {
        if(element == yarr[i])
        {
            //Does this so that it doesn't print multiple times
            printf("%d\n", element);
        }
    }
}

void test_binsearch()
{
    int arr[] = {1, 2, 3, 4, 5};
    
    assert(binsearch(arr, 1) == 1);
    assert(binsearch(arr, 5) == 5);
    assert(binsearch(arr, 3) == 3);
    assert(binsearch(arr, 6) == 0);
}

int main(int argc, char *argv[])
{
    test_binsearch();
    
    return 0;
}