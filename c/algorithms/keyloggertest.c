#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "keylogger.h"

void test_keylog()
{
    // Test when input is not NULL
    FILE *fPtr = fopen("test_keylogger.txt", "w+");
    fprintf(fPtr, "a");
    rewind(fPtr);
    
    keylog();
    
    char c;
    bool success = false;
    while((c = fgetc(fPtr)) != EOF)
    {
        if(c == 'a')
        {
            success = true;
            break;
        }
    }
    
    fclose(fPtr);
    
    if(success)
        printf("Test 1 Passed\n");
    else
        printf("Test 1 Failed\n");
    
    // Test when hour is 24
    fPtr = fopen("test_keylogger.txt", "w+");

    keylog();
    
    if(feof(fPtr))
        printf("Test 2 Passed\n");
    else
        printf("Test 2 Failed\n");
    
    fclose(fPtr);
}

int main()
{
    test_keylog();
    return 0;
}