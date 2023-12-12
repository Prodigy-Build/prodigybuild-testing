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

void testInsert() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    assert(RootPtr->data == 5);
    assert(RootPtr->left == NULL);
    assert(RootPtr->right == NULL);
    
    Insert(&RootPtr, 3);
    assert(RootPtr->left->data == 3);
    assert(RootPtr->left->left == NULL);
    assert(RootPtr->left->right == NULL);
    
    Insert(&RootPtr, 7);
    assert(RootPtr->right->data == 7);
    assert(RootPtr->right->left == NULL);
    assert(RootPtr->right->right == NULL);
    
    Insert(&RootPtr, 2);
    assert(RootPtr->left->left->data == 2);
    assert(RootPtr->left->left->left == NULL);
    assert(RootPtr->left->left->right == NULL);
    
    Insert(&RootPtr, 4);
    assert(RootPtr->left->right->data == 4);
    assert(RootPtr->left->right->left == NULL);
    assert(RootPtr->left->right->right == NULL);
    
    Insert(&RootPtr, 6);
    assert(RootPtr->right->left->data == 6);
    assert(RootPtr->right->left->left == NULL);
    assert(RootPtr->right->left->right == NULL);
    
    Insert(&RootPtr, 8);
    assert(RootPtr->right->right->data == 8);
    assert(RootPtr->right->right->left == NULL);
    assert(RootPtr->right->right->right == NULL);
}

void testSearch() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);
    Insert(&RootPtr, 4);
    Insert(&RootPtr, 6);
    Insert(&RootPtr, 8);
    
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 2) == 1);
    assert(Search(RootPtr, 4) == 1);
    assert(Search(RootPtr, 6) == 1);
    assert(Search(RootPtr, 8) == 1);
    
    assert(Search(RootPtr, 1) == 0);
    assert(Search(RootPtr, 9) == 0);
    assert(Search(RootPtr, 0) == 0);
    assert(Search(RootPtr, 10) == 0);
}

int main() {
    testInsert();
    testSearch();
    
    return 0;
}