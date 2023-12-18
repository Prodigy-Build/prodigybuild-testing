#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int binsearch(int yarr[10], int element)
{
    int size = sizeof(yarr) / sizeof(yarr[0]);
    int mid = size / 2;
    int left = mid;
    int right = size - 1;
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
}

void binsearch_test()
{
    int yarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Test case 1: Search for existing element in the array
    int element1 = 5;
    binsearch(yarr, element1);  // Expected output: 5
    
    // Test case 2: Search for non-existing element in the array
    int element2 = 11;
    binsearch(yarr, element2);  // Expected output:
}

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

void keylog_test()
{
    // Test case 1: Input is not null
    // Simulating input by assigning a character value
    char input1 = 'a';
    stdin = fopen("/dev/null", "r");  // Mock stdin
    fprintf(stdin, "%c", input1);
    keylog();  // Expected output: keylogger.txt file updated with 'a'
    fclose(stdin);
    
    // Test case 2: Input is null
    stdin = fopen("/dev/null", "r");  // Mock stdin
    keylog();  // Expected output: keylogger.txt file is not updated
    fclose(stdin);
}

int main()
{
    binsearch_test();
    keylog_test();
}