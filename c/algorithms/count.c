#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_array(int *arr, int size) 
{
    printf("[");
    
    for(int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        
        if(i != size - 1)
            printf(", ");
    }
    
    printf("]");
}

void count(int num) 
{
    if(num > 20)
    {
        int *arr = malloc(sizeof(int) * num);
        
        for(int i = 0; i < num; i++)
            arr[i] = i;
            
        print_array(arr, num);
        
        free(arr);
    } 
    else
    {
        int *arr = malloc(sizeof(int) * num);
        
        for(int i = 0; i < num; i++)
            arr[i] = i;
            
        print_array(arr, num);
        
        free(arr);
    }
}

int main()
{
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
    return 0;
}