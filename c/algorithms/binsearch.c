#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = (sizeof(yarr)/sizeof(int)) / 2;
    int left = mid;
    int right = 10 - left;
    extern int i;
    
    if(element == yarr[mid])
    printf("%d", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
            //Does this so that it doesn't print multiple times
            printf("%d", yarr[i]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int arr[10];
    sscanf(argv[1], "%d", &arr[0]);
    sscanf(argv[2], "%d", &arr[1]);
    sscanf(argv[3], "%d", &arr[2]);
    sscanf(argv[4], "%d", &arr[3]);
    sscanf(argv[5], "%d", &arr[4]);
    sscanf(argv[6], "%d", &arr[5]);
    sscanf(argv[7], "%d", &arr[6]);
    sscanf(argv[8], "%d", &arr[7]);
    sscanf(argv[9], "%d", &arr[8]);
    sscanf(argv[10], "%d", &arr[9]);
    
    int element;
    sscanf(argv[11], "%d", &element);
    
    binsearch(arr, element);
}