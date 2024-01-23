// Implementation of Binary Search Tree 
#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* CreateNode(int value) {
    BST* newNode = (BST*) malloc(sizeof(BST));
    if(newNode==NULL){
        printf("Error! Unable to allocate memory\n");
        exit(-1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(BST** root, int value) {
    if (*root == NULL) {
        *root = CreateNode(value);
    } else if (value <= (*root)->data) {
        Insert(&(*root)->left, value);
    } else {
        Insert(&(*root)->right, value);
    }
}

int Search(BST* root, int item) {
    if(root == NULL) {
        return 0;
    } else if(item == root->data) {
        return 1;
    } else if(item < root->data) {
        return Search(root->left, item);
    } else {
        return Search(root->right, item);
    }
}

void main() {
    BST* root = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        Insert(&root, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(Search(root, key)==1) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
}