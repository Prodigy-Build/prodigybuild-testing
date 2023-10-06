// Implementation of Binary Search Tree 
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

// Unit test cases
void test() {
    struct BST* RootPtr = NULL;
    
    // Test case 1: Single element in the tree
    Insert(&RootPtr, 10);
    int result1 = Search(RootPtr, 10);
    printf("Test case 1: %d\n", result1);

    // Test case 2: Multiple elements in the tree
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 15);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 12);
    Insert(&RootPtr, 17);
    int result2 = Search(RootPtr, 7);
    printf("Test case 2: %d\n", result2);

    // Test case 3: Element not present in the tree
    int result3 = Search(RootPtr, 20);
    printf("Test case 3: %d\n", result3);
}

int main() {
    test();
    return 0;
}