```c
#include <stdio.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = 10 - mid;
    extern int i;

    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
    return 0;
};

int main(int argc, char* argv[])
{
    int arr[10];
    for (int i = 0; i < argc - 1 && i < 10; ++i)
    {
        arr[i] = atoi(argv[i + 1]);
    }
    binsearch(arr, atoi(argv[argc - 1]));
    return 0;
}
```