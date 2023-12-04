```c/algorithms/binsearch.c
#include <stdio.h>

int binsearch(int* yarr, int element)
{
    int mid = sizeof(*yarr) / sizeof(int) / 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    
    if(element == *yarr[mid])
    printf("%d", *yarr[mid]);
    
    if(element != *yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    binsearch(arr, atoi(argv[0]));
}
```