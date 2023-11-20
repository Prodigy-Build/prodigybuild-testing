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
	while (j<=high) 
		b[k++]=a[j++];
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

// Unit test for merge function
void test_merge()
{
  int arr[] = {83, 20, 9, 50, 115, 61, 17};
  int n = sizeof(arr) / sizeof(arr[0]);

  merge(arr, 0, n/2, n-1);
  
  int expected[] = {9, 20, 50, 83, 17, 61, 115};
  
  for(int i=0; i<n; i++)
  {
    assert(arr[i] == expected[i]);
  }
}

// Unit test for mergesort function
void test_mergesort()
{
  int arr[] = {83, 20, 9, 50, 115, 61, 17};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergesort(arr, 0, n-1);
  
  int expected[] = {9, 17, 20, 50, 61, 83, 115};
  
  for(int i=0; i<n; i++)
  {
    assert(arr[i] == expected[i]);
  }
}

// main fucntion
int main()
{
  // Run unit tests
  test_merge();
  test_mergesort();

  printf("All tests passed.\n");
	
  return 0;
}