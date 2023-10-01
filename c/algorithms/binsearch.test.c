```c
#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid - 1;
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
                printf("%d", yarr[i]);
            }
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    binsearch(yarr, element);
    return 0;
}
```