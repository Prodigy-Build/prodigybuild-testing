#include <stdio.h>

void binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
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

int main(int argc, char *argv[])
{
    int arr[10];
    int element;
    printf("Enter the array elements: ");
    for(int i=0; i<10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    binsearch(arr, element);
}