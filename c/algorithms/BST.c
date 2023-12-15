// Implementation of Binary Search Tree 
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

int Search(struct BST* RootPtr, int item) { /*Implemented search using recursion*/
    if(RootPtr == NULL) {
        return 0; /*Returns 0 if list is empty*/
    } else if(item == RootPtr->data) {
        return 1; /*Returns 1 when element found*/
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        return Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

void test_Insert() {
    struct BST* RootPtr = NULL;
    int value = 10;
    Insert(&RootPtr, value);
    if (RootPtr == NULL || RootPtr->data != value || RootPtr->left != NULL || RootPtr->right != NULL) {
        printf("Insert failed\n");
    } else {
        printf("Insert passed\n");
    }
}

void test_Search_found() {
    struct BST* RootPtr = CreateNode();
    RootPtr->data = 10;
    int item = 10;
    int result = Search(RootPtr, item);
    if (result != 1) {
        printf("Search found failed\n");
    } else {
        printf("Search found passed\n");
    }
}

void test_Search_not_found() {
    struct BST* RootPtr = CreateNode();
    RootPtr->data = 20;
    int item = 10;
    int result = Search(RootPtr, item);
    if (result != 0) {
        printf("Search not found failed\n");
    } else {
        printf("Search not found passed\n");
    }
}

int main() {
    test_Insert();
    test_Search_found();
    test_Search_not_found();
    return 0;
}