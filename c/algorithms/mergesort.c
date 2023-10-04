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

void test(){
	int a[7] = {83, 20, 9, 50, 115, 61, 17};
	int n = 7;

	mergesort(a, 0, n-1);
	
	assert(a[0] == 9);
	assert(a[1] == 17);
	assert(a[2] == 20);
	assert(a[3] == 50);
	assert(a[4] == 61);
	assert(a[5] == 83);
	assert(a[6] == 115);
}

int main(){
	test();
	return 0;
}