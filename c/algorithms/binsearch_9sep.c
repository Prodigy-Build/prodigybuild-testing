#include <stdio.h>
#include <assert.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / 2;
    int left = 0;
    int right = sizeof(yarr) - 1;
    extern int i;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
	
		if (yarr[mid] == element) {
			return mid;
		}

		if (yarr[mid] < element) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

    return -1;
};

void test_binsearch() {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//Assert statements for testing
	assert(binsearch(arr, 5) == 4);
	assert(binsearch(arr, 11) == -1);
	assert(binsearch(arr, 1) == 0);
	assert(binsearch(arr, 10) == 9);
}

int main(int argc, char *argv[])
{
    test_binsearch();
    return 0;
}
