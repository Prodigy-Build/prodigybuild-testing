#include <stdio.h>

void binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", mid);
    
    if(element != yarr[right])
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
    int yarr[10];
    int element;
    
    sscanf(argv[1], "%d", &element);
    
    for(int i=0; i<10; i++){
        sscanf(argv[i+2], "%d", &yarr[i]);
    }
    
    binsearch(yarr, element);
}