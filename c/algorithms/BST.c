#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* CreateNode(int value) {
    struct BST* newNode = (struct BST*) malloc(sizeof(struct BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}

void Insert(struct BST** rootPtr, int value) {
    if (*rootPtr == NULL) {
        *rootPtr = CreateNode(value);
    } else if (value <= (*rootPtr)->data) {
        Insert(&(*rootPtr)->left, value);
    } else {
        Insert(&(*rootPtr)->right, value);
    }
}

int Search(struct BST* rootPtr, int item) {
    if (rootPtr == NULL) {
        return 0;
    } else if (item == rootPtr->data) {
        return 1;
    } else if (item < rootPtr->data) {
        return Search(rootPtr->left, item);
    } else {
        return Search(rootPtr->right, item);
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
    } while (cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if (Search(rootPtr, key) == 0) {
        printf("\nNot Found\n");
    } else {
        printf("\nFound\n");
    }
    return 0;
}