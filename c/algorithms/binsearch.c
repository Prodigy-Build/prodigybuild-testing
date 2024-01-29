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
        return mid;
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr[i]);
                return i;
            }
        }
    }
    
    return -1;
}

void test_binsearch()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: element is in the middle
    assert(binsearch(arr, 5) == 4);
    
    // Test case 2: element is in the left half
    assert(binsearch(arr, 2) == 1);
    
    // Test case 3: element is in the right half
    assert(binsearch(arr, 8) == 7);
    
    // Test case 4: element is not in the array
    assert(binsearch(arr, 11) == -1);
    
    printf("All test cases passed!\n");
}

int main(int argc, char *argv[])
{
    test_binsearch();
    
    return 0;
}