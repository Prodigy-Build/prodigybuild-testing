```c
#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    
    if (element == yarr[mid])
        printf("%d", mid);
    
    for (int i = 0; i < left; i++)
    {
        if (element == yarr[i])
        {
            // Does this so that it doesn't print multiple times
            printf("%d", i);
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = atoi(argv[1]);
    
    binsearch(arr, size, element);
    
    return 0;
}
```