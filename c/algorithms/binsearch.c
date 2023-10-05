#include <stdio.h>

int binsearch(int yarr[], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    int left = 0;
    int right = size - 1;
    extern int i;
    
    if(element == yarr[mid])
        printf("%d", yarr[mid]);
        
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
                printf("%d", yarr[i]);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binsearch(yarr, atoi(argv[1]));
}