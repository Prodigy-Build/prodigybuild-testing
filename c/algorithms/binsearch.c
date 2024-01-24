#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
}

void test_binsearch()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: element is in the middle
    assert(binsearch(arr, 5) == 5);
    
    // Test case 2: element is not in the rightmost position
    assert(binsearch(arr, 9) == 9);
    
    // Test case 3: element is not in the leftmost position
    assert(binsearch(arr, 2) == 2);
    
    // Test case 4: element is not in the array
    assert(binsearch(arr, 11) == -1);
    
    printf("All test cases pass\n");
}

int main(int argc, int argv[])
{
    test_binsearch();
    return 0;
}