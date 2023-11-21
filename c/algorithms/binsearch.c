#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    
    if(element == mid)
    printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
            //Does this so that it doesn't print multiple times
            printf("%d", i);
            }
        }
    }
};

void test_binsearch()
{
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    assert(binsearch(arr, 15) == 6);
    assert(binsearch(arr, 3) == 1);
    assert(binsearch(arr, 19) == 9);
    assert(binsearch(arr, 20) == -1);
    assert(binsearch(arr, -1) == -1);
}

int main(int argc, int argv[])
{
    test_binsearch();
    return 0;
}