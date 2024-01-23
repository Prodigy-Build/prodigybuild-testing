/* 
 * The code provided is not testable as it contains syntax errors, incorrect data types, and logical issues.
 * Here is the refactored code:
 */

#include <stdio.h>

int linsearch(char **yarr, char *val)
{
    for(int i = 0; i < sizeof(yarr) / sizeof(yarr[0]); i++)
    {
        if(strcmp(yarr[i], val) == 0)
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
    int index = linsearch(yarr, val);
    
    if(index != -1)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}