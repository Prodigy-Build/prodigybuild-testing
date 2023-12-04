// Implementation of Binary Search Tree 
#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST *createNode() {
    struct BST* newNode = (struct BST*) malloc(sizeof(struct BST));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
};

void insert(struct BST** rootPtr, int value) {
    struct BST* temp = *rootPtr;
    if (temp == NULL) { /*When list is empty*/
        struct BST* newNode = createNode();
        newNode->data = value;
        *rootPtr = newNode;
    } else if (value <= temp->data) { /*If user value is less then current node value insert in left of the node...*/
        struct BST* newNode = createNode();
        newNode->data = value;
        temp->left = newNode;
    } else { /*If user value is greater then current node value insert at right of the node*/
        struct BST* newNode = createNode();
        newNode->data = value;
        temp->right = newNode;
    }
}

int search(struct BST* rootPtr, int item) { /*Implemented search using recursion*/
    if(rootPtr == NULL) {
        return 0; /*Returns 0 if list is empty*/
    } else if(item == rootPtr->data) {
        return 1; /*Returns 1 when element found*/
    } else if(item < rootPtr->data) {
        return search(rootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        return search(rootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

int main() {
    struct BST* rootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        insert(&rootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(search(rootPtr, key) == 0) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
    
    return 0;
}