#include <stdio.h>
#include <assert.h>

void test_binsearch() {
    // Test case 1: element is in the middle of the array
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result1 = binsearch(arr1, 5);
    assert(result1 == 5);

    // Test case 2: element is not in the array
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result2 = binsearch(arr2, 11);
    assert(result2 == -1);

    // Test case 3: element is in the first half of the array
    int arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result3 = binsearch(arr3, 3);
    assert(result3 == 3);

    // Test case 4: element is in the second half of the array
    int arr4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result4 = binsearch(arr4, 8);
    assert(result4 == 8);

    // Test case 5: all elements in the array are the same
    int arr5[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int result5 = binsearch(arr5, 1);
    assert(result5 == -1);
}

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = mid + 1;

    if(element == yarr[mid])
        return mid;

    if(element != yarr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    test_binsearch();
    return 0;
}