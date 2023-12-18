// Unit test cases for BST.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
}

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
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 1);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 6);
    assert(RootPtr->data == 5);
    assert(RootPtr->left->data == 3);
    assert(RootPtr->right->data == 7);
    assert(RootPtr->left->left->data == 1);
    assert(RootPtr->right->left->data == 6);
    printf("Insert function passed all tests!\n");
}

void test_Search() {
    struct BST* RootPtr = CreateNode();
    RootPtr->data = 5;
    RootPtr->left = CreateNode();
    RootPtr->left->data = 3;
    RootPtr->right = CreateNode();
    RootPtr->right->data = 7;
    RootPtr->left->left = CreateNode();
    RootPtr->left->left->data = 1;
    RootPtr->right->left = CreateNode();
    RootPtr->right->left->data = 6;
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 1) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 6) == 1);
    assert(Search(RootPtr, 2) == 0);
    assert(Search(RootPtr, 4) == 0);
    printf("Search function passed all tests!\n");
}

int main() {
    test_Insert();
    test_Search();
    return 0;
}