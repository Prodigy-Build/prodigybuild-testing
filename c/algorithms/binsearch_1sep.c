#include <stdio.h>

int binsearch(int yarr[], int num_elements, int element)
{
    int mid;
    int left = 0;
    int right = num_elements - 1;
    
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (yarr[mid] == element)
            return mid;

        if (yarr[mid] < element)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
};

int main()
{
    int y_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ele = 6;
    int ele_index = binsearch(y_arr, 10, ele);
    printf("Element %d found at index %d\n", ele, ele_index);

    ele = 11;
    ele_index = binsearch(y_arr, 10, ele);
    printf("Element %d found at index %d\n", ele, ele_index);

    return 0;
}
