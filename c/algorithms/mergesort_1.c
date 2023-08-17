

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<assert.h>

// function to merge the sub-arrays
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
	while 
		(j<=high) b[k++]=a[j++];
		for (k=low;k<=high;k++)
	        a[k]=b[k];
}

// merge sort function
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

// main fucntion
int main()
{
	int a[7] = {83, 20, 9, 50, 115, 61, 17};
	int n = 7;

	mergesort(a, 0, n-1);
	
	printf("\n Sorted numbers are: ");

	// function to print the sorted array
	int k;
	for(k = 0; k < 7; k++)
	    printf("%d, ",a[k]);
	
	// Unit test cases
	int test_arr1[7] = {83, 20, 9, 50, 115, 61, 17};
	int test_arr2[7] = {1, 2, 3, 4, 5, 6, 7};
	int test_arr3[7] = {7, 6, 5, 4, 3, 2, 1};
	int test_arr4[7] = {1, 1, 1, 1, 1, 1, 1};
	
	mergesort(test_arr1, 0, 6);
	assert(test_arr1[0] == 9);
	assert(test_arr1[1] == 17);
	assert(test_arr1[2] == 20);
	assert(test_arr1[3] == 50);
	assert(test_arr1[4] == 61);
	assert(test_arr1[5] == 83);
	assert(test_arr1[6] == 115);
	
	mergesort(test_arr2, 0, 6);
	assert(test_arr2[0] == 1);
	assert(test_arr2[1] == 2);
	assert(test_arr2[2] == 3);
	assert(test_arr2[3] == 4);
	assert(test_arr2[4] == 5);
	assert(test_arr2[5] == 6);
	assert(test_arr2[6] == 7);
	
	mergesort(test_arr3, 0, 6);
	assert(test_arr3[0] == 1);
	assert(test_arr3[1] == 2);
	assert(test_arr3[2] == 3);
	assert(test_arr3[3] == 4);
	assert(test_arr3[4] == 5);
	assert(test_arr3[5] == 6);
	assert(test_arr3[6] == 7);
	
	mergesort(test_arr4, 0, 6);
	assert(test_arr4[0] == 1);
	assert(test_arr4[1] == 1);
	assert(test_arr4[2] == 1);
	assert(test_arr4[3] == 1);
	assert(test_arr4[4] == 1);
	assert(test_arr4[5] == 1);
	assert(test_arr4[6] == 1);
	
	return 0;
}