// Unit Test Cases

// Test Case 1: Empty array
int arr1[] = {};
selection_sort(arr1, 0);

// Test Case 2: Array with a single element
int arr2[] = {5};
selection_sort(arr2, 1);

// Test Case 3: Array with multiple elements in ascending order
int arr3[] = {1, 2, 3, 4, 5};
selection_sort(arr3, 5);

// Test Case 4: Array with multiple elements in descending order
int arr4[] = {5, 4, 3, 2, 1};
selection_sort(arr4, 5);

// Test Case 5: Array with multiple elements already sorted
int arr5[] = {1, 2, 3, 4, 5};
selection_sort(arr5, 5);

// Test Case 6: Array with multiple elements in random order
int arr6[] = {3, 1, 4, 2, 5};
selection_sort(arr6, 5);

// Test Case 7: Array with duplicate elements
int arr7[] = {2, 4, 6, 2, 8};
selection_sort(arr7, 5);

// Test Case 8: Array with negative elements
int arr8[] = {-4, -2, 0, -3, -1};
selection_sort(arr8, 5);

// Test Case 9: Array with large size
int arr9[1000];
for (int i = 0; i < 1000; i++)
    arr9[i] = i;
selection_sort(arr9, 1000);

// Test Case 10: Array with large size in reverse order
int arr10[1000];
for (int i = 999; i >= 0; i--)
    arr10[i] = i;
selection_sort(arr10, 1000);