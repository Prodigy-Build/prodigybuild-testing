#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* createNode(int value) {
    struct BST* newNode = (struct BST*) malloc(sizeof(struct BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

void insert(struct BST** rootPtr, int value) {
    struct BST* temp = *rootPtr;
    if (temp == NULL) {
        *rootPtr = createNode(value);
    } else if (value <= temp->data) {
        if (temp->left == NULL) {
            temp->left = createNode(value);
        } else {
            insert(&(temp->left), value);
        }
    } else {
        if (temp->right == NULL) {
            temp->right = createNode(value);
        } else {
            insert(&(temp->right), value);
        }
    }
}

int search(struct BST* rootPtr, int item) {
    if (rootPtr == NULL) {
        return 0;
    } else if (item == rootPtr->data) {
        return 1;
    } else if (item < rootPtr->data) {
        return search(rootPtr->left, item);
    } else {
        return search(rootPtr->right, item);
    }
}

int main() {
    struct BST* rootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        insert(&rootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while (cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if (search(rootPtr, key) == 0) {
        printf("\nNot Found\n");
    } else {
        printf("\nFound\n");
    }

    return 0;
}