#include <stdio.h>

int binsearch(int yarr[], int len, int element)
{
    int mid = len / 2;
    int left = 0;
    int right = len - 1;
    
    if(element == yarr[mid])
        printf("%d", element);
    
    if(element != yarr[right])
    {
        for(int i = left; i < right; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", element);
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(yarr) / sizeof(yarr[0]);
    int element = atoi(argv[1]);
    binsearch(yarr, len, element);
    return 0;
}