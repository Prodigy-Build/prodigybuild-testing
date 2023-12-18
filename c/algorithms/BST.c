#include <stdio.h>
#include <stdlib.h>

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

struct BST *CreateTestBST() {
    struct BST* RootPtr = NULL;
    int items[] = {5, 3, 1, 4, 7, 6, 8};
    int numItems = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < numItems; i++) {
        Insert(&RootPtr, items[i]);
    }

    return RootPtr;
}

void TestSearch(int item, int expected) {
    struct BST* RootPtr = CreateTestBST();

    if(Search(RootPtr, item) == expected) {
        printf("Test Passed\n");
    } else {
        printf("Test Failed\n");
    }
}

int main() {
    TestSearch(5, 1);
    TestSearch(10, 0);

    return 0;
}