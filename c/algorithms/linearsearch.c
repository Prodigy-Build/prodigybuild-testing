#include <stdio.h>
#include <string.h>

int linsearch(char yarr[][50], int size, const char *val)
{
    for(int i = 0; i < size; i++)
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
    char yarr[][50] = {"Shluck much", "much Shluck"};
    const char *val = "Shluck much";
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int result = linsearch(yarr, size, val);
    if (result != -1) {
        printf("Element found at index %d", result);
    } else {
        printf("Element not found");
    }
    return 0;
}