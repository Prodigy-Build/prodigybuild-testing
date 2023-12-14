#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int n = sizeof(yarr) / sizeof(yarr[0]);  // find the length of the array

    for(int i = 0; i < n; i++)
    {
        if(yarr[i] == val)
        {
            return i;          // return the index of the element if found
        }    
    }
    
    return -1;              // return -1 if the element is not found
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"};  // change int* to char*
    char *val = "Shluck much";                      // change int to char*

    int result = linsearch(yarr, val);
    
    if(result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}