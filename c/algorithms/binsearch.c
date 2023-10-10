#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = 0;
    int right = size - 1;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr + mid);
    }
    
    if(element != yarr[right])
    {
        for(i = left; i < mid; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr + i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    binsearch(argv, argc - 2, argv[argc - 1]);
}