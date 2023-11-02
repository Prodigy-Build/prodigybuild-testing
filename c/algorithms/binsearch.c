#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)(&yarr[0]) / 2 - mid;
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
    return 0;
}

int main(int argc, char *argv[])
{
    int yarr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int element = yarr[0] + yarr[1];
    binsearch(yarr, element);
    return 0;
}