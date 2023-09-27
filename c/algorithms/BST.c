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
    if (temp == NULL) {
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } else if (value <= temp->data) {
        Insert(&temp->left, value);
    } else {
        Insert(&temp->right, value);
    }
}

int Search(struct BST* RootPtr, int item) {
    if (RootPtr == NULL) {
        return 0;
    } else if (item == RootPtr->data) {
        return 1;
    } else if (item < RootPtr->data) {
        return Search(RootPtr->left, item);
    } else {
        return Search(RootPtr->right, item);
    }
}

void testInsert() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);
    Insert(&RootPtr, 4);
    
    assert(RootPtr->data == 5);
    assert(RootPtr->left->data == 3);
    assert(RootPtr->right->data == 7);
    assert(RootPtr->left->left->data == 2);
    assert(RootPtr->left->right->data == 4);
}

void testSearch() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);
    Insert(&RootPtr, 4);
    
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 2) == 1);
    assert(Search(RootPtr, 4) == 1);
    assert(Search(RootPtr, 1) == 0);
    assert(Search(RootPtr, 6) == 0);
}

int main() {
    testInsert();
    testSearch();
    
   return 0;
}