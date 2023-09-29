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
    
    return 0;
}

void test_keylog() {
    // Test case 1: Input is not NULL
    FILE * fPtr;
    fPtr = fopen("keylogger_test1.txt", "w+");
    assert(fPtr != NULL);
    const char *a = "test input";
    fprintf(fPtr, a);
    fclose(fPtr);

    // Test case 2: Input is NULL
    fPtr = fopen("keylogger_test2.txt", "w+");
    assert(fPtr != NULL);
    fclose(fPtr);

    // Test case 3: Hour is not 24
    fPtr = fopen("keylogger_test3.txt", "w+");
    assert(fPtr != NULL);
    a = "test input";
    fprintf(fPtr, a);
    fclose(fPtr);

    // Test case 4: Hour is 24
    fPtr = fopen("keylogger_test4.txt", "w+");
    assert(fPtr != NULL);
    a = "test input";
    fprintf(fPtr, a);
    fclose(fPtr);
}

int main()
{
    test_keylog();
    keylog();
    
    return 0;
}