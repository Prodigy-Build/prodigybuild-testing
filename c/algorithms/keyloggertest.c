#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void test_keylog()
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = "Hello, World!";
    
    if (a != NULL)
        fprintf(fPtr, "%s", a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if (hour == 24)
        fclose(fPtr);

    fclose(fPtr);
}

int main()
{
    test_keylog();
    
    return 0;
}