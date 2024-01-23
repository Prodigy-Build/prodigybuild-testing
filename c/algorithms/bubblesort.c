#include <stdio.h>

void swap(int *xp, int *yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int *arr, int len) 
{
    for (int i = 0; i < len-1; i++)             
        for (int j = 0; j < len-i-1; j++)  
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main(void) 
{
    int arr[] = {3, 9, 4, 8, 7, 6, 1, 2, 0, 10};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    bubble_sort(arr, len);

    printf("[");
    for (int i=0; i < len; i++)
        printf("%d, ", arr[i]);
    printf("\b\b]\n");
    return 0;
}