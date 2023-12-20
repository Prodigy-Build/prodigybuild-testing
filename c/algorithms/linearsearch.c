#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr)/sizeof(yarr[0]); // calculate the size of the array
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
    }
    return 1; // return 1 if the value is not found
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5}; // change the array to contain integer values
    int val = 3; // change the value to an integer
    linsearch(yarr, val);
}