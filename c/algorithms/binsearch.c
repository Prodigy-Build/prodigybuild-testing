#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid - 1;
    int right = mid + 1;
    extern int i;

    if(element == yarr[mid])
        printf("%d", yarr[mid]);

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

int main(int argc, int *argv[])
{
    binsearch(argv[0], argc, argv[1]);
}