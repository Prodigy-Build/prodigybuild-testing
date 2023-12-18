#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int n = sizeof(yarr)/sizeof(yarr[0]); // calculate the length of the array

    for(int i = 0; i < n; i++)
    {
        if(yarr[i] == val)
        {
            return 0;
        }    
    }

    return 1;
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"}; // declare yarr as an array of strings
    char *val = "Shluck much"; // declare val as a string
    linsearch(yarr, val);
}