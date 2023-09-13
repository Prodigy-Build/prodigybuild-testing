#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int start = 0;
    int end = size-1;
    while (start <= end) {
        int mid = (start+end)/2;
        if (yarr[mid] == element) 
            return mid;
        else if (yarr[mid] < element) 
            start = mid+1;
        else 
            end = mid-1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int result = binsearch(arr, n, 10);
    (result == -1)? printf("Element is not present"
                            " in array\n")
               : printf("Element is present at "
                            "index %d\n", result);
    return 0;
}


// Test Cases

void run_tests(void)
{
    int test1[] = {1, 2, 3, 4, 5};
    printf("%d\n", binsearch(test1, 5, 5) == 4); 
    
    int test2[] = {2, 4, 6, 8, 10};
    printf("%d\n", binsearch(test2, 5, 2) == 0);

    int test3[] = {2, 4, 6, 8, 10};
    printf("%d\n", binsearch(test3, 5, 10) == 4); 

    int test4[] = {2, 4, 6, 8, 10};
    printf("%d\n", binsearch(test4, 5, 1) == -1);
}

int main(void)
{
    setbuf(stdout, NULL);
    run_tests();
    return 0;
}
