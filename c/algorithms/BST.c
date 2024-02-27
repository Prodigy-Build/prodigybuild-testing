#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* createNode(int value) {
    BSTNode* newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(BSTNode** rootPtr, int value) {
    BSTNode* temp = *rootPtr;
    if (temp == NULL) {
        *rootPtr = createNode(value);
    } else if (value <= temp->data) {
        insert(&(temp->left), value);
    } else {
        insert(&(temp->right), value);
    }
}

int search(BSTNode* root, int item) {
    if (root == NULL) {
        return 0;
    } else if (item == root->data) {
        return 1;
    } else if (item < root->data) {
        return search(root->left, item);
    } else {
        return search(root->right, item);
    }
}

int main() {
    BSTNode* root = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        insert(&root, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while (cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key) == 0) {
        printf("\nNot Found\n");
    } else {
        printf("\nFound\n");
    }

    return 0;
}