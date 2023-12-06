The refactored code is:

```c
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
}

void Insert(struct BST** rootPtr, int value) {
    struct BST* temp = *rootPtr;
    if (temp == NULL) { /*When list is empty*/
        *rootPtr = CreateNode(value);
    } else if (value <= temp->data) { /*If user value is less than or equal to current node value insert in the left of the node...*/
        if (temp->left == NULL) {
            temp->left = CreateNode(value);
        } else {
            Insert(&(temp->left), value);
        }
    } else { /*If user value is greater than current node value insert at the right of the node*/
        if (temp->right == NULL) {
            temp->right = CreateNode(value);
        } else {
            Insert(&(temp->right), value);
        }
    }
}

int Search(struct BST* rootPtr, int item) { /*Implemented search using recursion*/
    if(rootPtr == NULL) {
        return 0; /*Returns 0 if the tree is empty*/
    } else if(item == rootPtr->data) {
        return 1; /*Returns 1 when element found*/
    } else if(item < rootPtr->data) {
        return Search(rootPtr->left, item); /*Otherwise search in the left subtree if the searching value is less than the current node value*/
    } else {
        return Search(rootPtr->right, item); /*Otherwise search in the right subtree if the searching value is greater than the current node value*/
    }
}

int main() {
    struct BST* rootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        Insert(&rootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if(Search(rootPtr, key) == 0) {
        printf("\nNot Found\n");
    } else {
        printf("\nFound\n");
    }
    
    return 0;
}
```