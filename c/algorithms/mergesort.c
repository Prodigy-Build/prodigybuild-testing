#include <stdio.h>
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

void test_merge() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    merge(a, 0, 2, 4);
    printf("Merged array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test_mergesort() {
    int a[7] = {83, 20, 9, 50, 115, 61, 17};
    mergesort(a, 0, 6);
    printf("Sorted numbers are: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    test_merge();
    test_mergesort();
    return 0;
}