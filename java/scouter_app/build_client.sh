#!/usr/bin/env bash

##########################
# download maven from :
#   https://maven.apache.org

if [ ! -z "${JAVA_11_HOME}" ]; then
	echo JAVA_11_HOME: ${JAVA_11_HOME}
	JAVA_HOME=${JAVA_11_HOME}
fi

MVN="`which mvn`"
if [ ! -z "${MAVEN_HOME}" ]; then
	echo MAVEN_HOME: ${MAVEN_HOME}
	MVN="${MAVEN_HOME}/bin/mvn"
fi

if [ -z "$MVN" ]; then
    echo maven not found.
	exit 1
else
    $MVN -Dtycho.debug.resolver=true -X -f ./scouter.client.build/pom.xml clean package
fi

#####################################################
# Unit Test Cases for binsearch function

#include <stdio.h>

int binsearch(int yarr[10], int element)
{
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    
    if(element == mid)
    printf("%d", &mid);
    
    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
            //Does this so that it doesn't print multiple times
            printf("%d", i);
            }
        }
    }
};


void test_binsearch()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int element1 = 5; // element present in the array
    int element2 = 15; // element not present in the array
    
    printf("Testing binsearch function\n");
    
    // Test Case 1: Element present in the array
    printf("Test Case 1: Element present in the array\n");
    printf("Expected Output: 4\n");
    printf("Actual Output: %d\n", binsearch(arr, element1));
    
    // Test Case 2: Element not present in the array
    printf("Test Case 2: Element not present in the array\n");
    printf("Expected Output: \n");
    printf("Actual Output: %d\n", binsearch(arr, element2));
}


int main(int argc, int argv[])
{
    test_binsearch();
    return 0;
}