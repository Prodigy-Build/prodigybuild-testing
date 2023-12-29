#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = 10 - mid;
    extern int i;

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

int main(int argc, char* argv[])
{
    int yarr[10];

    for (int i = 0; i < argc - 1; i++)
    {
        sscanf(argv[i+1], "%d", &yarr[i]);
    }

    binsearch(yarr, argc > 1 ? atoi(argv[argc-1]) : 0);
}