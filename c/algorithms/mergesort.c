#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int a[],int low,int mid ,int high)
{
	int b[20];
	int i = low, j = mid + 1, k = low;
	while(i <= mid && j <= high)
	{
		if(a[i]<=a[j])
		    b[k++]=a[i++];
		else
		    b[k++]=a[j++];
	}
	while (i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=low;k<=high;k++)
	    a[k]=b[k];
}

void mergesort(int a[],int low,int high)
{
	if(low>=high)
	  return;
	int mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}

int main()
{
	int a[7] = {83, 20, 9, 50, 115, 61, 17};

	mergesort(a, 0, 6);
	
	printf("\n Sorted numbers are: ");
	int k;
	for(k = 0; k < 7; k++)
	    printf("%d, ", a[k]);
	return 0;
}