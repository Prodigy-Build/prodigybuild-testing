// Unit test for merge() function
void test_merge()
{
	int a[] = {2, 5, 7, 1, 3, 6};
	int low = 0;
	int mid = 2;
	int high = 5;
	int expected[] = {1, 2, 3, 5, 6, 7};
	
	merge(a, low, mid, high);

	for(int i = 0; i <= high; i++)
	{
		if(a[i] != expected[i])
		{
			printf("merge() test failed.\n");
			return;
		}
	}

	printf("merge() test passed.\n");
}

// Unit test for mergesort() function
void test_mergesort()
{
	int a[] = {5, 3, 9, 1, 7, 4};
	int n = 6;
	int expected[] = {1, 3, 4, 5, 7, 9};

	mergesort(a, 0, n-1);

	for(int i = 0; i < n; i++)
	{
		if(a[i] != expected[i])
		{
			printf("mergesort() test failed.\n");
			return;
		}
	}

	printf("mergesort() test passed.\n");
}

// Mock main function for testing
int main()
{
	test_merge();
	test_mergesort();

	return 0;
}