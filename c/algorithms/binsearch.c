#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
    int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    for(i = 0; i < left; i++)
    {
        if(element == yarr[i])
        {
            printf("%d", yarr[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int element = atoi(argv[1]);
    
    binsearch(yarr, size, element);
    return 0;
}