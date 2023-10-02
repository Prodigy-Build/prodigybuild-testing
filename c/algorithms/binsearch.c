```c
#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = size / 2;
    int right = size - left;
    extern int i;
    
    if (element == yarr[mid]) {
        printf("%d", mid);
    }
    
    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == yarr[i]) {
                // Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 3;
    
    binsearch(arr, size, element);
    
    return 0;
}
```