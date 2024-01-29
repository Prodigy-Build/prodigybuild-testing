#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / 2;
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
                return i;
            }
        }
    }

    return -1;
};

void test_binsearch() {
    int test_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binsearch(test_array, 5) == 5);
    assert(binsearch(test_array, 11) == -1);
}

int main(int argc, int argv[])
{
    binsearch(argv[0], argv[1]);

    test_binsearch();

    return 0;
}