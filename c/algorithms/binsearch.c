#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d\n", mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = atoi(argv[i]);
    }
    binsearch(arr, atoi(argv[10]));
}