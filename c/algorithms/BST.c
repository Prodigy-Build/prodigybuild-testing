/* 
   Reformatted code and added comments
   File: c/algorithms/BST.c
*/

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>

// Define structure for BST nodes
struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

// Function to create a new BST node
struct BST *CreateNode() {
    struct BST* new_node = (struct BST*) malloc(sizeof(struct BST));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
};

// Function to insert a node in the BST
void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) { 
        // If BST is empty, create new node
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } 
    else if (value <= temp->data) { 
        // Insert at left of the BST node, if input value is less than current node value
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } 
    else { 
        // Insert at right of the BST node, if input value is greater than current node value
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

// Function to search for an element in the BST
int Search(struct BST* RootPtr, int item) { 
    if(RootPtr == NULL) {
        // Return 0 if the BST is empty
        return 0; 
    } 
    else if(item == RootPtr->data) {
        // Return 1 if element is found in the BST
        return 1; 
    } 
    else if(item < RootPtr->data) {
        // Search left side of BST if searching value is less than the current node value
        Search(RootPtr->left, item); 
    } 
    else {
        // Search right side of BST if searching value is greater than the current node value
        Search(RootPtr->right, item); 
    }
}

void main() {
    struct BST* RootPtr = NULL;
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

    if(Search(RootPtr, key) == 1) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
}