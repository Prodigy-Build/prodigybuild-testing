Unit Test Cases:

1. Test case for swap function:
    int a = 5;
    int b = 10;
    swap(&a, &b);
    // After swap, a should be 10 and b should be 5

2. Test case for partition function:
    int a[] = {4, 2, 9, 6, 7};
    int l = 0;
    int h = 4;
    int pivotIndex = partition(a, l, h);
    // pivotIndex should be 2

3. Test case for quick_sort function:
    int a[] = {4, 2, 9, 6, 7};
    int l = 0;
    int h = 4;
    quick_sort(a, l, h);
    // After sorting, a should be {2, 4, 6, 7, 9}