#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <vector>

// function to merge the sub-arrays
void merge(std::vector<int>& a, int low, int mid, int high)
{
    std::vector<int> b(high - low + 1); //same size of a[]
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++]; //copying the elements
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = b[k - low];
}

// merge sort function
void mergesort(std::vector<int>& a, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

TEST_CASE("Merge Sort")
{
    std::vector<int> a = {83, 20, 9, 50, 115, 61, 17};
    int n = a.size();

    mergesort(a, 0, n - 1);

    std::vector<int> expected = {9, 17, 20, 50, 61, 83, 115};

    REQUIRE(a == expected);
}