#include <iostream>

int binsearch(int arr[], int size, int element)
{
    int mid = size / 2;
    int left = mid;
    int right = size - left;

    if(element == arr[mid])
    {
      std::cout << mid;
    }

    for(int i = 0; i < left; i++)
    {
        if(element == arr[i])
        {
            //Does this so that it doesn't print multiple times
            std::cout << i;
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = std::stoi(argv[1]);
    binsearch(arr, size, element);
}