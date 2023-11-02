```c
#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    
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
}

int main(int argc, char *argv[])
{
    int yarr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    binsearch(yarr, 2 + 3);
    return 0;
}
```