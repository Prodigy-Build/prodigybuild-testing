#include <stdio.h>
#include <string.h>

#define SIZE 2

int linsearch(char *yarr[], char* val)
{
    for(int i = 0; i < SIZE; i++)
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
    char *yarr[SIZE] = {"Shluck much", "much Shluck"};
    char *val = "Shluck much";
    linsearch(yarr, val);
}