// Refactored Code

#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* createNode(int value) {
    BST* newNode = (BST*)malloc(sizeof(BST));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BST* insert(BST* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left  = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int search(BST* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    
    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main() {
    BST* root = NULL;
    int value, cont, key;
    do {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("\n1 to continue inserting, 0 to Exit: ");
        scanf("%d", &cont);
    } while(cont == 1);
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    printf((search(root, key)) ? "\nKey Found\n" : "\nKey Not Found\n");
    return 0;
}