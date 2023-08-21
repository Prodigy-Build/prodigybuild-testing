

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
int partition(int *a, int l, int h);
void quick_sort(int *a, int l, int h);

int main()
{
    int size;
    printf("Size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;

    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }

    swap(&a[p], &a[j]);

    return j;
}

void quick_sort(int a[], int l, int h)
{
    int p;

    if (l < h)
    {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }

    return;
}

// Unit Test Cases
void test_swap() {
    int a = 5;
    int b = 10;
    swap(&a, &b);
    assert(a == 10);
    assert(b == 5);
}

void test_partition() {
    int a[] = {5, 10, 15, 20, 25};
    int p = partition(a, 0, 4);
    assert(p == 2);
    assert(a[0] == 5);
    assert(a[1] == 10);
    assert(a[2] == 15);
    assert(a[3] == 20);
    assert(a[4] == 25);
}

void test_quick_sort() {
    int a[] = {5, 10, 15, 20, 25};
    quick_sort(a, 0, 4);
    assert(a[0] == 5);
    assert(a[1] == 10);
    assert(a[2] == 15);
    assert(a[3] == 20);
    assert(a[4] == 25);
}

int main() {
    test_swap();
    test_partition();
    test_quick_sort();
    printf("All tests passed!\n");
    return 0;
}