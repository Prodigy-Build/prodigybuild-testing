#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Testable keylog function
void keylog(FILE *fPtr)

    if (fPtr != NULL) {
        const char *a = getchar();
        if (a != NULL)
            fprintf(fPtr, "%s", a);
    }
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if (hour == 24)
        fclose(fPtr);
}

// Testable main function
int main()
{
    FILE *fPtr = fopen("keylogger.txt", "w+");
    if (fPtr != NULL) {
        keylog(fPtr);
        fclose(fPtr);
    } else {
        printf("Error opening file! Exiting...\n");
    }
    
    return 0;
}

// Unit test cases

void test_keylog()
{
    FILE *fPtr = fopen("test.txt", "w+");
    if (fPtr != NULL) {
        keylog(fPtr);
        fclose(fPtr);
    }
}

void test_main()
{
    keylog(NULL);
}
