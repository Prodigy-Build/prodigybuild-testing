#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / sizeof(int) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(int) - left;
    int i;
    
    if(element == yarr[mid])
    printf("%d", &mid);
    
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
    binsearch(argv[0], atoi(argv[1]));
}