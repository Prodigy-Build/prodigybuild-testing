```c
#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    
    if (element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if (element != yarr[right])
    {
        for (int i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    for (int i = 1; i < argc; i++)
    {
        yarr[i - 1] = atoi(argv[i]);
    }
    
    binsearch(yarr, atoi(argv[0]));
}
```