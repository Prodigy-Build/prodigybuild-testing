```
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST *CreateNode() {
    struct BST* new = (struct BST*) malloc(sizeof(struct BST));
    new->left = NULL;
    new->right = NULL;
    return new;
}

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) {
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } else if (value <= temp->data) {
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } else {
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
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

void test_CreateNode() {
    struct BST* node = CreateNode();
    assert(node != NULL);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node);
}

void test_Insert() {
    struct BST* root = NULL;
    Insert(&root, 50);
    Insert(&root, 30);
    Insert(&root, 70);
    Insert(&root, 20);
    Insert(&root, 40);
    
    assert(root->data == 50);
    assert(root->left->data == 30);
    assert(root->left->left->data == 20);
    assert(root->left->right->data == 40);
    assert(root->right->data == 70);
    assert(root->right->left == NULL);
    assert(root->right->right == NULL);
}

void test_Search() {
    struct BST* root = NULL;
    Insert(&root, 50);
    Insert(&root, 30);
    Insert(&root, 70);
    Insert(&root, 20);
    Insert(&root, 40);
    
    assert(Search(root, 50) == 1);
    assert(Search(root, 30) == 1);
    assert(Search(root, 20) == 1);
    assert(Search(root, 40) == 1);
    assert(Search(root, 70) == 1);
    assert(Search(root, 10) == 0);
    assert(Search(root, 60) == 0);
    assert(Search(root, 80) == 0);
}

int main() {
    test_CreateNode();
    test_Insert();
    test_Search();
    printf("All tests passed.\n");
    return 0;
}
```