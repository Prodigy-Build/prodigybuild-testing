#include <stdio.h>
#include <stdlib.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr)/sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid - 1;
    int right = mid + 1;
    extern int i;

    if(element == yarr[mid])
    printf("%d", yarr[mid]);

    if(element != yarr[right])
    {
        for(i = 0; i <= left; i++)
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
    int arr_size = argc - 2;
    int yarr[arr_size];
    
    for(int j = 2; j < argc; j++)
    {
        yarr[j - 2] = atoi(argv[j]);
    }
    
    binsearch(yarr, atoi(argv[1]));
}