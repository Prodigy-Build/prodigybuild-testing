### New code with unit test cases:

```c
#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    
    if(element == yarr[mid])
    {
        return mid;
    }
    
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int pivot = left + (right - left) / 2;
        
        if(yarr[pivot] == element)
        {
            return pivot;
        }
        
        if(yarr[pivot] < element)
        {
            left = pivot + 1;
        }
        else
        {
            right = pivot - 1;
        }
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = atoi(argv[1]);
    
    int index = binsearch(yarr, element);
    
    if(index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }
    
    return 0;
}
```