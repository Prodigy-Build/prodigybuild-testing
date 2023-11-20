```c
#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = (sizeof(yarr)/sizeof(yarr[0])) / 2;
    int left = 0;
    int right = (sizeof(yarr)/sizeof(yarr[0])) - 1;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d\n", mid);
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10];
    for (int i = 1; i < argc; i++)
    {
        arr[i-1] = atoi(argv[i]);
    }
    binsearch(arr, atoi(argv[argc-1]));
}
```