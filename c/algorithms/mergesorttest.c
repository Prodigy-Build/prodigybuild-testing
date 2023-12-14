#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>

void merge(int a[],int low,int mid ,int high)
{
	int b[20];
	int i, j, k;
	i = low, j = mid + 1,k = low;
	while(i <= mid && j <= high)
	{
		if(a[i]<=a[j])
		    b[k++]=a[i++];
		else
		   b[k++]=a[j++];
	}
	while (i<=mid)
		b[k++]=a[i++];
	while 
		(j<=high) b[k++]=a[j++];
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
    int a1[5] = {1, 3, 5, 2, 4};
    merge(a1, 0, 2, 4);
    assert(a1[0] == 1);
    assert(a1[1] == 2);
    assert(a1[2] == 3);
    assert(a1[3] == 4);
    assert(a1[4] == 5);
    
    int a2[5] = {6, 8, 10, 7, 9};
    merge(a2, 0, 2, 4);
    assert(a2[0] == 6);
    assert(a2[1] == 7);
    assert(a2[2] == 8);
    assert(a2[3] == 9);
    assert(a2[4] == 10);
    
    int a3[5] = {11, 12, 13, 14, 15};
    merge(a3, 0, 2, 4);
    assert(a3[0] == 11);
    assert(a3[1] == 12);
    assert(a3[2] == 13);
    assert(a3[3] == 14);
    assert(a3[4] == 15);
}

void test_mergesort()
{
    int a1[5] = {3, 2, 1, 5, 4};
    mergesort(a1, 0, 4);
    assert(a1[0] == 1);
    assert(a1[1] == 2);
    assert(a1[2] == 3);
    assert(a1[3] == 4);
    assert(a1[4] == 5);
    
    int a2[5] = {7, 6, 10, 8, 9};
    mergesort(a2, 0, 4);
    assert(a2[0] == 6);
    assert(a2[1] == 7);
    assert(a2[2] == 8);
    assert(a2[3] == 9);
    assert(a2[4] == 10);
    
    int a3[5] = {15, 12, 11, 13, 14};
    mergesort(a3, 0, 4);
    assert(a3[0] == 11);
    assert(a3[1] == 12);
    assert(a3[2] == 13);
    assert(a3[3] == 14);
    assert(a3[4] == 15);
}

int main()
{
    test_merge();
    test_mergesort();
    
	int a[7] = {83, 20, 9, 50, 115, 61, 17};
	int n = 7;

	mergesort(a, 0, n-1);
	
	printf("\n Sorted numbers are: ");

	int k;
	for(k = 0; k < 7; k++)
	    printf("%d, ",a[k]);
	return 0;
}