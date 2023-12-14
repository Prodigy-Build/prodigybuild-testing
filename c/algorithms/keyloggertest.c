#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = getchar();
    
    if(a != NULL)
    {
        fprintf(fPtr, "%c", a);
        fclose(fPtr);
    }
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
}

// Unit test for keylog function
void test_keylog()
{
    // Create mock of getchar function
    const char *mock = "a";
    FILE *pFile = fopen("mock.txt", "w+");
    fprintf(pFile, "%s", mock);
    fclose(pFile);
    
    // Redirect standard input to the file containing the mock input
    freopen("mock.txt", "r", stdin);
    
    // Call the keylog function
    keylog();
    
    // Restore standard input
    freopen("/dev/tty", "r", stdin);
    
    // Open the keylogger.txt file to check the output
    FILE *fPtr = fopen("keylogger.txt", "r");
    
    if(fPtr != NULL)
    {
        char buffer[100];
        fgets(buffer, sizeof(buffer), fPtr);
        fclose(fPtr);
        
        // Check if the output is correct
        if(strcmp(buffer, "a") == 0)
            printf("Unit test for keylog function: PASSED\n");
        else
            printf("Unit test for keylog function: FAILED\n");
    }
    else
    {
        printf("Unit test for keylog function: FAILED\n");
    }
    
    // Clean up the mock and output files
    remove("mock.txt");
    remove("keylogger.txt");
}

int main()
{
    // Run the unit test for keylog function
    test_keylog();
    
    return 0;
}