#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST *CreateNode(int value) {
    BST* newNode = (BST*) malloc(sizeof(BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}

void Insert(BST** RootPtr, int value) {
    BST* temp = *RootPtr;
    if (temp == NULL) {
        *RootPtr = CreateNode(value);
    } else if (value <= temp->data) {
        temp->left = CreateNode(value);
    } else {
        temp->right = CreateNode(value);
    }
}

int Search(BST* RootPtr, int item) {
    if (RootPtr == NULL) {
        return 0;
    } else if (item == RootPtr->data) {
        return 1;
    } else if (item < RootPtr->data) {
        return Search(RootPtr->left, item);
    } else {
        return Search(RootPtr->right, item);
    }
}

int main() {
    BST* RootPtr = NULL;
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