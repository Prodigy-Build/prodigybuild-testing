#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "a"); // Open file in append mode

    const char a = getchar(); // Change variable a from const char* to char
    
    if(a != EOF) // Check for end of file marker instead of NULL
        fprintf(fPtr, "%c", a); // Use %c to print a single character
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour != 0) // Check if hour is not midnight to close the file
        fclose(fPtr);
}

int main()
{
    keylog();
    
    return 0; // Added return statement
}