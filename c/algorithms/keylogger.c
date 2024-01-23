#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int keylog()
{
    FILE *fPtr;
    
    // Open file with append mode
    fPtr = fopen("keylogger.txt", "a");
    if(fPtr == NULL)
    {
        printf("Unable to open file.\n");
        return 0;
    }

    // Get a character from stdin
    int c = getchar();
    
    // Check for end-of-file marker
    if(c != EOF)
    {
        // Write the character to the file
        putc(c, fPtr);
    }

    // Check the current hour every keystroke
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    // Transfer data from the buffer to the file and close the file at midnight
    if(hour == 0)
    {
        fflush(fPtr);
        fclose(fPtr);
    }
    
    return 0;
}

int main()
{
    while(1)
    {
        keylog();
    }

    return 0;
}