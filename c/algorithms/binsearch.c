#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = (int)&yarr[0] / sizeof(int);
    int right = left + 10;
    extern int i;

    if(element == yarr[mid])
        printf("%d\n", mid);

    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                //Does this so that it doesn't print multiple times
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }

    binsearch(arr, atoi(argv[argc-1]));

    return 0;
}