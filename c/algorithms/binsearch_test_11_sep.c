#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) / 2;
    int left = 0;
    int right = sizeof(yarr) / sizeof(yarr[0]) - 1;
    int i;
    
    while (left <= right) {
    mid = left + (right - left) / 2;
    
    if(yarr[mid] == element) 
    {
        printf("Element %d found at index %d \n", element, mid);
        return mid;
    }
    
    if(yarr[mid] < element)
        left = mid + 1;
    else 
        right = mid - 1;
    }
       
    printf("Element %d not found\n", element);
    return -1;
};

int main(int argc, char *argv[])
{
    int testArray[10] = {1,2,3,4,5,6,7,8,9,10};
    int testElement1 = 3;
    int testElement2 = 11;

    binsearch(testArray, testElement1);
    binsearch(testArray, testElement2);

    return 0;
}
