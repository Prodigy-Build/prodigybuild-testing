#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;

    int found = 0;
    
    if(element == yarr[mid])
    {
        printf("%d", &mid);
        found = 1;
    }
    
    if(found == 0)
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
                found = 1;
                break;
            }
        }
    }

    if(found == 0)
    {
        printf("Element not found");
    }
}

int main(int argc, int argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    binsearch(arr, element);
    return 0;
}