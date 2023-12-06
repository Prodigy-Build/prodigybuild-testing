#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(int); // calculate the size of the array
    
    for(int i = 0; i < size; i++) // iterate over each element of the array
    {
        if(yarr[i] == val) // check if the current element is equal to the value
        {
            return 1; // return 1 if found
        }    
    }
    
    return 0; // return 0 if not found
}

int main()
{
    int yarr[] = {1, 5, 2, 8, 9}; // example array of integers
    int val = 8; // example value to search for
    
    int result = linsearch(yarr, val); // perform linear search
    
    printf("Result: %d\n", result); // print the result
    
    return 0;
}