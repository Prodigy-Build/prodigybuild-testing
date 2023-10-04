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
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1
    int result1 = binsearch(yarr, 5);
    assert(result1 == 5);

    // Test case 2
    int result2 = binsearch(yarr, 10);
    assert(result2 == 10);

    // Test case 3
    int result3 = binsearch(yarr, -1);
    assert(result3 == -1);

    // Test case 4
    int result4 = binsearch(yarr, 0);
    assert(result4 == 0);
}

int main(int argc, int argv[])
{
    test_binsearch();
}