#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Function to write keylogs to file
void writeKeylog(const char *key)
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "a");

    if (fPtr != NULL)
    {
        fprintf(fPtr, "%s\n", key);
        fclose(fPtr);
    }
}

// Function to check if key is valid
bool isValidKey(const char *key)
{
    return (key != NULL && strlen(key) > 0);
}

// Function to perform key logging
void keylog()
{
    char key[512];

    printf("Enter a key: ");
    if (fgets(key, sizeof(key), stdin) != NULL)
    {
        // Remove trailing newline character
        if (key[strlen(key) - 1] == '\n')
            key[strlen(key) - 1] = '\0';

        if (isValidKey(key))
        {
            writeKeylog(key);
        }
    }
}

// Unit tests for writeKeylog function
void test_writeKeylog()
{
    // Test case 1: Valid key
    writeKeylog("test");
    // TODO: Assert that "test" is written to the file

    // Test case 2: Empty key
    writeKeylog("");
    // TODO: Assert that nothing is written to the file

    // Test case 3: Null key
    writeKeylog(NULL);
    // TODO: Assert that nothing is written to the file
}

// Unit tests for isValidKey function
void test_isValidKey()
{
    // Test case 1: Valid key
    bool isValid = isValidKey("test");
    // TODO: Assert that isValid is true

    // Test case 2: Empty key
    isValid = isValidKey("");
    // TODO: Assert that isValid is false

    // Test case 3: Null key
    isValid = isValidKey(NULL);
    // TODO: Assert that isValid is false
}

int main()
{
    // Run the keylog function
    keylog();

    // Run the unit tests
    test_writeKeylog();
    test_isValidKey();

    return 0;
}