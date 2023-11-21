#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr)/sizeof(int); // calculate the size of the array
    
    for(int i = 0; i < size; i++) // loop through the array
    {
        if(yarr[i] == val) // check if the element is equal to the target value
        {
            return 0; // return 0 if found
        } 
    }
    
    return 1; // return 1 if not found
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5}; // sample array
    int val = 3; // target value
    int result = linsearch(yarr, val); // call the linsearch function
    printf("Result: %d\n", result); // print the result
    
    return 0;
}