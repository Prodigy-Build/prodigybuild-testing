#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = 10 / 2;
    int left = mid;
    int right = 10 - left;
    extern int i;
    
    if(element == mid)
    printf("%d", mid);
    
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
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    binsearch(arr, atoi(argv[11]));
}