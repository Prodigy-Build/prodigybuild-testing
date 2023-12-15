#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
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
            printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    int element;
    for (int i = 0; i < 10; i++) {
        yarr[i] = atoi(argv[i+1]);
    }
    element = atoi(argv[argc]);

    binsearch(yarr, element);
}