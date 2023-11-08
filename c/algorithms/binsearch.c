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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: Element is present at the middle of the array
    assert(binsearch(arr, 5) == 5);
	
    // Test case 2: Element is present at the beginning of the array
    assert(binsearch(arr, 1) == 1);
	
    // Test case 3: Element is present at the end of the array
    assert(binsearch(arr, 10) == 10);
	
    // Test case 4: Element is not present in the array
    assert(binsearch(arr, 20) == -1);
}

int main(int argc, int argv[])
{
    test_binsearch();
}