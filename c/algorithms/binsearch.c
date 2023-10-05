#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;
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

int main(int argc, char* argv[])
{
    int yarr[argc - 2];
    int i;
    
    for(i = 0; i < argc - 2; i++)
    {
        yarr[i] = atoi(argv[i + 2]);
    }

    binsearch(yarr, argc - 2, atoi(argv[1]));
    return 0;
}