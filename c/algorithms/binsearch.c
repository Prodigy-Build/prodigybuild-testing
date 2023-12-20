#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    
    if(element == yarr[mid])
    {
        printf("%d", mid);
    }
    
    if(element != yarr[right])
    {
        for(int i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int size = argc - 2;
    int yarr[size];
    
    for(int i = 2; i < argc; i++)
    {
        yarr[i - 2] = atoi(argv[i]);
    }
    
    binsearch(yarr, size, atoi(argv[1]));
}