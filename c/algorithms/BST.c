// Implementation of Binary Search Tree 
#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST *CreateNode(int value) {
    struct BST* newNode = (struct BST*) malloc(sizeof(struct BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
};

struct BST* Insert(struct BST* RootPtr, int value) {
    if (RootPtr == NULL) { /*When tree is empty*/
        RootPtr = CreateNode(value);
    } else if (value <= RootPtr->data) { /*If user value is less then current node value insert in left of the node...*/
        RootPtr->left = Insert(RootPtr->left, value);
    } else { /*If user value is greater then current node value insert at right of the node*/
        RootPtr->right = Insert(RootPtr->right, value);
    }
    return RootPtr;
}

int Search(struct BST* RootPtr, int item) { /*Implemented search using recursion*/
    if(RootPtr == NULL) {
        return 0; /*Returns 0 if tree is empty*/
    } else if(item == RootPtr->data) {
        return 1; /*Returns 1 when element found*/
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        return Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

int main() {
    struct BST* RootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        RootPtr = Insert(RootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(Search(RootPtr, key)) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
    
    return 0;
}