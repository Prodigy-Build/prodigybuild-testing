// Reformatted code of Binary Search Tree with proper indentation and added comments
#include <stdio.h>
#include <stdlib.h>

// Definition of Binary Search Tree Node
struct BST {
    int data;                  // holds data
    struct BST* left;          // pointer to left child
    struct BST* right;         // pointer to right child
};

// Function to create a new node
struct BST *CreateNode() {
    struct BST* newNode = (struct BST*) malloc(sizeof(struct BST));   // create new node
    newNode->left = NULL;                // initialize left child as NULL
    newNode->right = NULL;               // initialize right child as NULL
    return newNode; 
};

// Function to Insert a new node in BST
void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) {  // If the tree is empty
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } else if (value <= temp->data) {  // If value is less than node's data, put in left sub-tree
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } else {   // Else if value is greater than node's data, put in right sub-tree
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

// Function to search an item in BST
int Search(struct BST* RootPtr, int item) {
    if(RootPtr == NULL) {   
        return 0; // Return 0 if tree is empty
    } else if(item == RootPtr->data) {
        return 1; // Return 1 if the item is found 
    } else if(item < RootPtr->data) {
        Search(RootPtr->left, item); // Search in left sub-tree if item is less than node's data 
    } else {
        Search(RootPtr->right, item); // Search in right sub-tree if item is greater than node's data
    }
}

// Main function start 
void main() {
    struct BST* RootPtr = NULL;   // root node pointer
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        Insert(&RootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(Search(RootPtr, key) == 0) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
}