#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void merge(int a[],int low,int mid ,int high)
{
    int b[20]; //same size of a[]
    int i, j, k;
    i = low, j = mid + 1,k = low;
    while(i <= mid && j <= high)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++]; //copying the elements 
    }
    while (i<=mid)
        b[k++]=a[i++];
    while(j<=high) 
        b[k++]=a[j++];
        
    for (k=low;k<=high;k++)
        a[k]=b[k];
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low>=high)
        return;
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}

void test_merge()
{
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    int n = 7;

    merge(a, 0, n-1, n-1);

    for(int i = 0; i < n; i++)
        assert(a[i] == expected[i]);
}

void test_mergesort()
{
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    int n = 7;

    mergesort(a, 0, n-1);

    for(int i = 0; i < n; i++)
        assert(a[i] == expected[i]);
}

int main()
{
    test_merge();
    test_mergesort();

    printf("All test cases passed!\n");

    return 0;
}