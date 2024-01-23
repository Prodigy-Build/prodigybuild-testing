// Refactored code

#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* CreateNode(int value) {
    struct BST* new_node = (struct BST*) malloc(sizeof(struct BST));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) {
        *RootPtr = CreateNode(value);
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

int Search(struct BST* RootPtr, int item) {
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
    struct BST* RootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        Insert(&RootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while (cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    if (Search(RootPtr, key) == 1) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }

    return 0;
}