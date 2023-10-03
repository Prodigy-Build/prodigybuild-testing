#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// Function to test the keylog function
void test_keylog() {
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    assert(fPtr != NULL);

    char c = getchar();
    
    if(c != '\0')
        fprintf(fPtr, "%c", c);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

int main()
{
    test_keylog();
    return 0;
}