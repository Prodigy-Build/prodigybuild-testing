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

void test() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 10);
    Insert(&RootPtr, 20);
    Insert(&RootPtr, 15);
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 25);

    assert(Search(RootPtr, 10) == 1);
    assert(Search(RootPtr, 20) == 1);
    assert(Search(RootPtr, 15) == 1);
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 25) == 1);
    assert(Search(RootPtr, 30) == 0);
    assert(Search(RootPtr, 0) == 0);
}

int main() {
    test();
    return 0;
}