#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int a[], int low, int mid, int high) {
    int b[20];
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void mergesort(int a[], int low, int high) {
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

bool test_merge() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    merge(a, 0, 2, 6);
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    for (int i = 0; i < 7; i++) {
        if (a[i] != expected[i])
            return false;
    }
    return true;
}

bool test_mergesort() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    mergesort(a, 0, 6);
    int expected[7] = {9, 17, 20, 50, 61, 83, 115};
    for (int i = 0; i < 7; i++) {
        if (a[i] != expected[i])
            return false;
    }
    return true;
}

int main() {
    if (test_merge() && test_mergesort()) {
        printf("All tests passed.\n");
    } else {
        printf("Tests failed.\n");
    }
    return 0;
}