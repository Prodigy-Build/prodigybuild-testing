#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gtest/gtest.h>

void keylog(const char *input)
{
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "w+");
    
    if (fPtr != NULL) {
        if (input != NULL)
            fprintf(fPtr, "%s", input);
        
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        int hour = tm_struct->tm_hour;

        if (hour == 24)
            fclose(fPtr);
    }
}

TEST(KeylogTest, ValidInput)
{
    // Arrange
    const char *input = "hello world";
    
    // Act
    keylog(input);
    
    // Assert: Check if the file contains the correct input
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "r");
    char buffer[100];
    fgets(buffer, 100, fPtr);

    EXPECT_STREQ(buffer, input);
    
    fclose(fPtr);
}

TEST(KeylogTest, NullInput)
{
    // Arrange
    const char *input = NULL;
    
    // Act
    keylog(input);
    
    // Assert: Check if the file is empty
    FILE * fPtr;
    fPtr = fopen("keylogger.txt", "r");
    char buffer[100];
    fgets(buffer, 100, fPtr);

    EXPECT_STREQ(buffer, "");
    
    fclose(fPtr);
}

TEST(KeylogTest, Hour24)
{
    // Arrange
    const char *input = "hello world";
    
    // Act
    keylog(input);
    
    // Assert: Check if the file is closed at 24th hour
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;

    bool isFileClosed = (hour == 24);

    EXPECT_TRUE(isFileClosed);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}