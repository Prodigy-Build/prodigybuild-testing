#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
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
}

int main(int argc, char *argv[])
{
    // Convert command line arguments to integers
    int yarr[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        yarr[i] = atoi(argv[i + 1]);
    }
    
    // Call binsearch function
    binsearch(yarr, atoi(argv[argc - 1]));
    
    return 0;
}