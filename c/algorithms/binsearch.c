#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = 10 - left; // assuming yarr is always of size 10
    extern int i;
    
    if(element == mid)
    printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i]) // Fixed condition
            {
            //Does this so that it doesn't print multiple times
            printf("%d", i);
            }
        }
    }
};

int main(int argc, int *argv[])
{
    binsearch(argv[0], argv[1]);
}