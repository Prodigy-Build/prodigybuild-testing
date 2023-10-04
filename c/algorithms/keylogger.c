#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool test_keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger_test.txt", "w+");

    fopen("keylogger_test.txt", "w");
    const char *a = "test";
    
    if(a != NULL)
        fprintf(fPtr, a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
        
    return true;
}

int main()
{
    test_keylog();
}