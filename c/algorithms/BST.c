// Implementation of Binary Search Tree 
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
        Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

// Unit test cases for Insert and Search functions
void test() {
    struct BST* RootPtr = NULL;
    int key;

    // Test case 1: Inserting a value and searching for it should return 1
    Insert(&RootPtr, 5);
    assert(Search(RootPtr, 5) == 1);

    // Test case 2: Inserting multiple values and searching for them should return 1
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 1);
    Insert(&RootPtr, 4);
    Insert(&RootPtr, 6);
    Insert(&RootPtr, 8);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 1) == 1);
    assert(Search(RootPtr, 4) == 1);
    assert(Search(RootPtr, 6) == 1);
    assert(Search(RootPtr, 8) == 1);

    // Test case 3: Searching for a value not present in the binary search tree should return 0
    assert(Search(RootPtr, 2) == 0);
    assert(Search(RootPtr, 9) == 0);
}

int main() {
    test();
    return 0;
}