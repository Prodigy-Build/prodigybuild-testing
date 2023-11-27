```c/algorithms/binsearch.c
#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = 10 - left;
    extern int i;

    if (element == yarr[mid])
        printf("%d", &mid);

    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, int *argv[])
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = atoi(argv[i]);
    }
    binsearch(arr, atoi(argv[10]));
}
```