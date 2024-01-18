#include <stdio.h>

int insertionsort(int unsorted[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = unsorted[i];
        j = i - 1;
        
        while(j >= 0 && unsorted[j] > key)
        {
            unsorted[j + 1] = unsorted[j];
            j = j - 1;
        }
        unsorted[j + 1] = key;
    }
    return 0;
}

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);

    insertionsort(unsorted, n);

    printf("Sorted array is \n");
    for(int i = 0; i < n; i++)
        printf("%d ", unsorted[i]);

    return 0;
}
