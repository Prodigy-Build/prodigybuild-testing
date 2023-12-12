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
        Insert(&temp->left, value); 
    } else { 
        Insert(&temp->right, value);
    }
}

int Search(struct BST* RootPtr, int item) {
    if(RootPtr == NULL) {
        return 0;
    } else if(item == RootPtr->data) {
        return 1;
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item);
    } else {
        return Search(RootPtr->right, item);
    }
}

void main() {
    struct BST* RootPtr = NULL;
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
}

void test_insert() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 5);
    assert(RootPtr->data == 5);
    assert(RootPtr->left == NULL);
    assert(RootPtr->right == NULL);

    Insert(&RootPtr, 2);
    assert(RootPtr->left->data == 2);
    assert(RootPtr->left->left == NULL);
    assert(RootPtr->left->right == NULL);

    Insert(&RootPtr, 7);
    assert(RootPtr->right->data == 7);
    assert(RootPtr->right->left == NULL);
    assert(RootPtr->right->right == NULL);

    Insert(&RootPtr, 1);
    assert(RootPtr->left->left->data == 1);
    assert(RootPtr->left->left->left == NULL);
    assert(RootPtr->left->left->right == NULL);

    Insert(&RootPtr, 3);
    assert(RootPtr->left->right->data == 3);
    assert(RootPtr->left->right->left == NULL);
    assert(RootPtr->left->right->right == NULL);

    printf("Insert function passed all tests.\n");
}

void test_search() {
    struct BST* RootPtr = NULL;

    Insert(&RootPtr, 5);
    Insert(&RootPtr, 2);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 1);
    Insert(&RootPtr, 3);

    assert(Search(RootPtr, 1) == 1);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 10) == 0);

    printf("Search function passed all tests.\n");
}

void run_tests() {
    test_insert();
    test_search();
}

void main() {
    run_tests();
}