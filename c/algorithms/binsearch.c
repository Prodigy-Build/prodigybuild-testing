#include <stdio.h>

int binsearch(int yarr[10], int element) 
{
    int mid = sizeof(yarr) / sizeof(int) / 2; // calculate the index of the middle element
    int left = 0; // initialize the left pointer
    int right = sizeof(yarr) / sizeof(int) - 1; // initialize the right pointer
    int i; // declare i outside the for loop
    
    if (element == yarr[mid]) // check if the element is at the middle index
    {
        printf("%d\n", mid);
    }
    
    if (element != yarr[right]) // check if the element is not at the right end of the array
    {
        for (i = 0; i < left; i++) // iterate over the elements from left to middle index
        {
            if (element == yarr[i]) // check if the element is found
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char* argv[]) 
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // example array
    int element = 5; // example element to search for
    binsearch(yarr, element);
    
    return 0;
}