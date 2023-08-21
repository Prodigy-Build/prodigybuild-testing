.

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

int main(int argc, int argv[])
{
    binsearch(argv[0], argv[1]);
}

// Unit testing
void test_binsearch() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    int expected = 5;
    int result = binsearch(arr, element);
    assert(result == expected);
}

int main() {
    test_binsearch();
    printf("All tests passed!");
    return 0;
}