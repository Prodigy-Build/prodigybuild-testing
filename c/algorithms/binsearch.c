#include <stdio.h>

// Function declaration
int binsearch(int yarr[], int element);

int main(int argc, char* argv[])
{
    int yarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;

    // Function call
    binsearch(yarr, element);

    return 0;
}

// Function definition
int binsearch(int yarr[], int element)
{
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = mid;
    int right = sizeof(yarr) / sizeof(yarr[0]);
    int i;

    if (element == yarr[mid])
    {
        printf("%d", &mid);
    }
    
    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == yarr[i])
            {
                printf("%d", i);
            }
        }
    }
}