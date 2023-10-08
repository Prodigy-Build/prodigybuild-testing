```c
#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;

    if (element == mid)
    {
        printf("%d", &mid);
    }

    if (element != yarr[right])
    {
        for (i = 0; i < left; i++)
        {
            if (element == i)
            {
                printf("%d", i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element = 5;
    binsearch(yarr, element);
}
```