#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
   int tmp;

   tmp = *a;
   *a = *b;
   *b = tmp;
}

int *find_min(int *ptr, int size)
{
   int *min;

   min = ptr;
   while(size--)
   {
       if(*ptr < *min)
           min = ptr;
       ptr++;
   }
   return (min);
}

void selection_sort(int *ptr, int size)
{
   int *min;

   while(--size)
   {
       if((min = find_min(ptr + 1, size)))
       {
           if(*ptr > *min)
               swap(ptr, min);
       }
       ptr++;
   }
}

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
   puts("Usage: ./your-executable-name [array size] [array]");
   puts("Example: ./your-executable-name 3 2 1 0");
   return EXIT_FAILURE;
   }
   int size = atoi(argv[1]);
   if(!size)
   {
   puts("Error: size of array can't be 0");
   return EXIT_FAILURE;
   }
   int *arr = (int *)malloc(size * sizeof(int));
   if(!arr)
   return EXIT_FAILURE;
   int i = 2;
   while(argv[i] && size--)
   {
   *arr++ = atoi(argv[i++]); 
   }   
   printf("Before sorting: ");
   for(int i = 0; i < size; i++)
   {
   printf("%d ", arr[i]);
   }
   putchar("\n");
   selection_sort(arr, size);

   printf("After sorting:  ");
   for(int i = 0; i < size; i++)
   {
   printf("%d ", arr[i]);
   }
   putchar("\n");
   return EXIT_SUCCESS;
}