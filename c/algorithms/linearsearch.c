#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr)/sizeof(yarr[0]); // get the size of the array

    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return 0; // value found
        }    
    }
    
    return 1; // value not found
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"}; // change int pointer to char pointer
    char *val = "Shluck Much"; // change int to char pointer
    linsearch(yarr, val);
}