#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) / sizeof(yarr[0]) - left;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d\n", yarr[mid]);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d\n", yarr[i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10];
    for (int i = 0; i < 10; i++)
    {
        yarr[i] = atoi(argv[i+1]);
    }
    binsearch(yarr, atoi(argv[11]));
    return 0;
}