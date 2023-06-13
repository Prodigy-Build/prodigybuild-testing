

#include <stdio.h>

//Function to search for a given element in an array
int binsearch(int yarr[], int element, int size)
{
    int mid = size / 2;
    int left = mid - 1;
    int right = size - left;
    extern int i;
    
    if(element == yarr[mid])
    {
        printf("%d", yarr[mid]);
    }
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == yarr[i])
            {
            //Does this so that it doesn't print multiple times
            printf("%d", yarr[i]);
            }
        }
    }
};

//API to accept parameters for search strings and use the search function to return a value
int search(int yarr[], int element, int size)
{
    return binsearch(yarr, element, size);
}

int main(int argc, int argv[])
{
    int size = argc - 1;
    int yarr[size];
    int element = argv[1];
    
    //Copy the elements from argv to yarr
    for(int i = 0; i < size; i++)
    {
        yarr[i] = argv[i+1];
    }
    
    search(yarr, element, size);
}