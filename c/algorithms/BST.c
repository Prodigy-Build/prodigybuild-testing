#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* CreateNode() {
    struct BST* new_node = (struct BST*) malloc(sizeof(struct BST));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}

void Insert(struct BST** RootPtr, int value) {
    if (*RootPtr == NULL) { // When list is empty
        struct BST* new_node = CreateNode();
        new_node->data = value;
        *RootPtr = new_node;
    } else if (value <= (*RootPtr)->data) { // If user value is less than or equal to current node value, insert in the left of the node
        Insert(&((*RootPtr)->left), value);
    } else { // If user value is greater than current node value, insert at the right of the node
        Insert(&((*RootPtr)->right), value);
    }
}

int Search(struct BST* RootPtr, int item) { // Implemented search using recursion
    if(RootPtr == NULL) {
        return 0; // Returns 0 if list is empty
    } else if(item == RootPtr->data) {
        return 1; // Returns 1 when element found
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item); // Otherwise search in the left side of binary tree if searching value is less than the current node value
    } else {
        return Search(RootPtr->right, item); // Otherwise search in the right side of binary tree if searching value is greater than the current node value
    }
}

int main() {
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

    if(Search(RootPtr, key) == 0) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
    
    return 0;
}