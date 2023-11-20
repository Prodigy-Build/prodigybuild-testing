#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
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
}

int main(int argc, char *argv[])
{
    // Assuming argv is passed correctly with elements for testing
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    int element = atoi(argv[11]);
    binsearch(arr, element);
    return 0;
}