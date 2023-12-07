#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* CreateNode(int value) {
    BSTNode* newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Insert(BSTNode** rootPtr, int value) {
    BSTNode* temp = *rootPtr;
    if (temp == NULL) {
        *rootPtr = CreateNode(value);
    } else if (value <= temp->data) {
        if (temp->left == NULL) {
            temp->left = CreateNode(value);
        } else {
            Insert(&(temp->left), value);
        }
    } else {
        if (temp->right == NULL) {
            temp->right = CreateNode(value);
        } else {
            Insert(&(temp->right), value);
        }
    }
}

int Search(BSTNode* root, int item) {
    if (root == NULL) {
        return 0;
    } else if (item == root->data) {
        return 1;
    } else if (item < root->data) {
        return Search(root->left, item);
    } else {
        return Search(root->right, item);
    }
}

int main() {
    BSTNode* root = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        Insert(&root, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while (cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if (Search(root, key) == 0) {
        printf("\nNot Found\n");
    } else {
        printf("\nFound\n");
    }

    return 0;
}