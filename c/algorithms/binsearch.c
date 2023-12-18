#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = 10 / 2; // Change sizeof(yarr) to 10
    int left = mid; // Remove (int)yarr / 2 - mid
    int right = 10 - left; // Change yarr to 10
    extern int i;
    
    if(element == yarr[mid]) // Change mid to yarr[mid]
        printf("%d", yarr[mid]); // Remove &mid
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i]) // Change i to yarr[i]
            {
                //Does this so that it doesn't print multiple times
                printf("%d", yarr[i]); // Change i to yarr[i]
            }
        }
    }
}

int main(int argc, char* argv[]) // Change argv[] to char* argv[]
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Add a test array
    binsearch(arr, 5); // Add a test case
}