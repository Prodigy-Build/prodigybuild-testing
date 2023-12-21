#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid; // left should start from mid
    int right = 10 - 1; // right should be the last index of the array
    extern int i;
    
    if(element == yarr[mid]) // compare with yarr[mid] instead of mid
        printf("%d\n", yarr[mid]); // print yarr[mid] instead of &mid
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d\n", yarr[i]); // print yarr[i] instead of i
            }
        }
    }
}

int main(int argc, int *argv[]) // argv should be a pointer to an array of integers
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // provide a sample array for testing
    binsearch(arr, 5); // perform a sample test for binsearch function
    return 0;
}