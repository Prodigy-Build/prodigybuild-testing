#include<stdio.h>

// function to merge the sub-arrays
void merge(int arr[],int lowIndex,int midIndex ,int highIndex)
{
    int tempArray[highIndex+1];
    int i, j, k;
    i = lowIndex;
    j = midIndex + 1;
    k = lowIndex;

    while(i <= midIndex && j <= highIndex)
    {
        if(arr[i] <= arr[j])
            tempArray[k++] = arr[i++];
        else
            tempArray[k++] = arr[j++];
    }

    while(i <= midIndex)
        tempArray[k++] = arr[i++];
    while(j <= highIndex)
        tempArray[k++] = arr[j++];

    for(k=lowIndex; k <= highIndex; k++)
        arr[k]=tempArray[k];
}

// merge sort function
void mergesort(int arr[],int lowIndex,int highIndex)
{
    if(lowIndex < highIndex)
    {
        int midIndex = lowIndex + (highIndex - lowIndex) / 2;
        mergesort(arr,lowIndex,midIndex);
        mergesort(arr,midIndex+1,highIndex);
        merge(arr,lowIndex,midIndex,highIndex);
    }
}

// main function
int main()
{
    int arr[] = {83, 20, 9, 50, 115, 61, 17};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, n-1);

    printf("\n Sorted numbers are: ");
    for(int k = 0; k < n; k++)
        printf("%d, ",arr[k]);
        
    return 0;
}