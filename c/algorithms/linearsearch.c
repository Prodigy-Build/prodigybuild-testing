```
#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(yarr[0]); // Calculate the size of the array

    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }
    }

    return 1; // Return 1 if the value is not found
}

int main()
{
    int yarr[] = {1, 2, 3, 4, 5}; // Define an array of integers
    int val = 3; // Define the value to search for

    linsearch(yarr, val);

    return 0;
}
```