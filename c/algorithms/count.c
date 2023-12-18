#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count(int num) 
{
    printf("[");
    
    if(num > 20)
    {
        int i;
        for(i = 0; i < num; i++)
            printf("\n%d, \n", i);
            
        if(i == num + 1)
            printf("]");
    } else
    {
        int i;
        for(i = 0; i < num; i++)
            printf("%d", i);
            
        if(i == num)
            printf("]");
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

#include <stdio.h>

int binsearch(int yarr[], int size, int element)
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        if(element < yarr[mid])
            right = mid - 1;
        else if(element > yarr[mid])
            left = mid + 1;
        else
            return mid;
    }
    
    return -1;
}

int main()
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int element = 4;
    int result = binsearch(yarr, size, element);
    printf("Index: %d\n", result);
    return 0;
}