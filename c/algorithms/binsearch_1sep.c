```c
#include <assert.h>

int binsearch(int yarr[], int n, int element)
{
    int left = 0, right = n - 1;
   
    while (left <= right) {
        int mid = left + (right - left) / 2;
  
        if (yarr[mid] == element)
            return mid;
  
        if (yarr[mid] < element)
            left = mid + 1;
  
        else
            right = mid - 1;
    }
   
    return -1;
}

void binsearch_test()
{
    int array[] = {2, 3, 4, 10, 40};
    int n = sizeof(array)/ sizeof(array[0]);

    assert(binsearch(array, n, 10) == 3);
    assert(binsearch(array, n, 2) == 0);
    assert(binsearch(array, n, 40) == 4);
    assert(binsearch(array, n, 5) == -1);
}

int main()
{
    binsearch_test();
    return 0;
}
```
