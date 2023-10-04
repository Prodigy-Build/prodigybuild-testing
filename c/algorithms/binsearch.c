```c/algorithms/binsearch.c```

```c
#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = mid + 1;
    extern int i;
    
    if (element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                // Does this so that it doesn't print multiple times
                printf("%d", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10] = {25, 30, 45, 50, 60, 70, 80, 85, 90, 100};
    int element = 85;
    
    binsearch(yarr, element);
    return 0;
}
```