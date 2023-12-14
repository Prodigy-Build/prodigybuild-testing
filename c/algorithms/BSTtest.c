#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST *CreateNode() {
    struct BST* new = (struct BST*) malloc(sizeof(struct BST));
    new->left = NULL;
    new->right = NULL;
    return new; 
};

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) { /*When list is empty*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } else if (value <= temp->data) { /*If user value is less then current node value insert in left of the node...*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } else { /*If user value is greater then current node value insert at right of the node*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

bool Search(struct BST* RootPtr, int item) { /*Implemented search using recursion*/
    if(RootPtr == NULL) {
        return false; /*Returns false if list is empty*/
    } else if(item == RootPtr->data) {
        return true; /*Returns true when element found*/
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        return Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

// Unit test cases

void test_Insert() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 4);
    
    // TODO: Add assertions to test if the tree was correctly created
}

void test_Search() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 4);
    
    // Test case 1: item exists in the tree
    bool result = Search(RootPtr, 3);
    printf("Search result (expected: true): %s\n", result ? "true" : "false");
    
    // Test case 2: item does not exist in the tree
    result = Search(RootPtr, 2);
    printf("Search result (expected: false): %s\n", result ? "true" : "false");
    
    // TODO: Add more test cases to cover different scenarios
}

void main() {
    // Run unit tests
    test_Insert();
    test_Search();
}