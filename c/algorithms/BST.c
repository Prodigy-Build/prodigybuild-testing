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
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } else {
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

int Search(struct BST* RootPtr, int item) {
    if(RootPtr == NULL) {
        return 0;
    } else if(item == RootPtr->data) {
        return 1;
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item);
    } else {
        return Search(RootPtr->right, item);
    }
}

void testInsert() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 10);
    assert(RootPtr->data == 10);
    Insert(&RootPtr, 5);
    assert(RootPtr->left->data == 5);
    Insert(&RootPtr, 15);
    assert(RootPtr->right->data == 15);
}

void testSearch() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 10);
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 15);
    assert(Search(RootPtr, 10) == 1);
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 15) == 1);
    assert(Search(RootPtr, 20) == 0);
}

int main() {
    testInsert();
    testSearch();
    printf("All tests passed!");
    return 0;
}