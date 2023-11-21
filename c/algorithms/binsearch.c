```c
#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = 10 - left; // Fixed incorrect calculation
    extern int i;
    
    // Add test case
    if(element == mid)
    {
        printf("%d", &mid);
        return mid;
    }
    
    // Add test cases
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
                return i;
            }
        }
    }
    return -1; // Added return value for all other cases
}

int main(int argc, char *argv[]) // Corrected argument types
{
    int arr[10]; // Create an array to pass to binsearch
    
    // Add test cases
    int element1 = 5;
    int element2 = 10;
    int result;
    
    result = binsearch(arr, element1);
    result = binsearch(arr, element2);
    
    return 0;
}
```