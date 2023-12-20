#include <stdio.h>
#include <stdbool.h> // added to use bool data type

bool linsearch(int *yarr, int val) // changed return type from int to bool
{
    for(int i = 0; i < sizeof(yarr); i++)
    {
        if(yarr[i] == val)
        {
            return true; // changed return value from 0 to true
        }    
    }
    return false; // added return statement outside the loop to return false if value is not found
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5}; // changed array to contain integer values
    int val = 3; // changed val to match the type of array elements
    linsearch(yarr, val);
}