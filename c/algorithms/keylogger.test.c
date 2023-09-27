#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void test_keylog()
{
    // Test input with a non-null character
    freopen("keylogger.txt", "w", stdout);
    const char *test_input = "A";
    printf("%s", test_input);
    fclose(stdout);
    
    // Test input with a null character
    freopen("keylogger.txt", "w", stdout);
    const char *test_input2 = "";
    printf("%s", test_input2);
    fclose(stdout);
    
    // Test input with multiple characters
    freopen("keylogger.txt", "w", stdout);
    const char *test_input3 = "Hello World";
    printf("%s", test_input3);
    fclose(stdout);
    
    // Test input with special characters
    freopen("keylogger.txt", "w", stdout);
    const char *test_input4 = "!@#$%^&*()";
    printf("%s", test_input4);
    fclose(stdout);
    
    // Test input with numbers
    freopen("keylogger.txt", "w", stdout);
    const char *test_input5 = "12345";
    printf("%s", test_input5);
    fclose(stdout);
    
    // Test input with whitespace characters
    freopen("keylogger.txt", "w", stdout);
    const char *test_input6 = " \t\n";
    printf("%s", test_input6);
    fclose(stdout);
}

int keylog()
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");

    const char *a = getchar();
    
    if(a != NULL)
        fprintf(fPtr, "%c", a);
    
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    
    if(hour == 24)
        fclose(fPtr);
        
    return 0;
}

int main()
{
    test_keylog();
    keylog();
    
    return 0;
}