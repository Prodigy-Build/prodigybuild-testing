#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr)/sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    extern int i;
    
    if(element == yarr[mid])
    printf("%d", &mid);
    
    if(element != yarr[right-1])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
            //Does this so that it doesn't print multiple times
            printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int searchElement = atoi(argv[1]);
    binsearch(arr, searchElement);
}