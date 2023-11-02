#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = sizeof(yarr) - left;
    extern int i;
    
    if(element == mid)
        printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
                //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arg0 = atoi(argv[1]);
    int arg1 = atoi(argv[2]);
    binsearch(arg0, arg1);
    
    return 0;
}