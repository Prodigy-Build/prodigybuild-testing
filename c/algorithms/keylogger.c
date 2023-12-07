#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Add return data type 'int' for keylog function
int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    // Remove redundant file open statement
    const char a = getchar();
    
    // Use single quotes for character literals
    // Use fputc instead of fprintf for writing a single character
    if(a != '\0')
        fputc(a, fPtr);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    // Change 24 to 0 to represent midnight
    if(hour == 0)
        fclose(fPtr);

    // Add return statement
    return 0;
}

int main()
{
    keylog();

    // Add return statement
    return 0;
}