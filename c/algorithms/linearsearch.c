#include <stdio.h>

int linsearch(int *yarr, int val)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    for(int i = 0; i < size; i++)
    {
        if(yarr[i] == val)
        {
            return i;
        }    
    }
    return -1;
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"};
    char *val = "Shluck much";
    int result = linsearch(yarr, val);
    if(result != -1) {
        printf("Value found at index: %d\n", result);
    } else {
        printf("Value not found\n");
    }
    return 0;
}