#include <stdio.h>

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
            printf("%d", yarr[i]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int arr[10], i;
  
    for (i=0; i<argc-1; i++) {
        arr[i] = atoi(argv[i+1]);
        printf("%s\n", argv[i+1]);
    }
  
    binsearch(arr, arr[argc-2]);
    
    return 0;
}