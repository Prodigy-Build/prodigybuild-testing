#include <stdio.h>
#include <string.h>

int linsearch(char *yarr[], int arrSize, char *val)
{
    for(int i = 0; i < arrSize; i++)
    {
        if(strcmp(yarr[i], val) == 0)
        {
            return 0;  
        }    
    }
    return 1;
}

int main()
{
    char *yarr[] = {"Shluck much", "much Shluck"};
    int arrSize = sizeof(yarr) / sizeof(yarr[0]);
    char *val = "Shluck Much";
    linsearch(yarr, arrSize, val);
}