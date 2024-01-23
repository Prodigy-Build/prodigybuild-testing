#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void SelectionSort(int arr[], int n)
{
  int i, j, min_idx;

  for (i = 0; i < n-1; i++)
  {
    min_idx = i;

    for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    swap(&arr[min_idx], &arr[i]);
  }
}

void printArray(int arr[], int n)
{
  int i;
  for (i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(int argc, char *argv[])
{
  if(argc < 3)
  {
    puts("Usage: ./your-executable-name [array size] [array]");
    puts("Example: ./your-executable-name 3 2 1 0");
    return EXIT_FAILURE;
  }
  int n = atoi(argv[1]);
  if(!n)
  {
    puts("Error: size of array can't be 0");
    return EXIT_FAILURE;
  }
  int *arr = (int *)malloc(n * sizeof(int));
  if(!arr)
    return EXIT_FAILURE;
  
  for (int i = 0; i < n; i++)
    arr[i] = atoi(argv[i+2]);

  printf("Before sorting: ");
  printArray(arr, n);

  SelectionSort(arr, n);

  printf("After sorting:  ");
  printArray(arr, n);
  
  free(arr);

  return 0;
}