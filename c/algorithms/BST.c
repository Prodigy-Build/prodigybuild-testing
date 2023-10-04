#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_Insert();
void test_Search();

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
};

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
    if(RootPtr == NULL) {
        return 0;
    } else if(item == RootPtr->data) {
        return 1;
    } else if(item < RootPtr->data) {
        Search(RootPtr->left, item);
    } else {
        Search(RootPtr->right, item);
    }
}

int main() {
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
    
    test_Insert();
    test_Search();

    return 0;
}

void test_Insert() {
    struct BST* RootPtr = NULL;
    
    Insert(&RootPtr, 5);

    assert(RootPtr->data == 5);

    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);

    assert(RootPtr->left->data == 3);
    assert(RootPtr->right->data == 7);
    assert(RootPtr->left->left->data == 2);
    
    printf("Insert function passed all test cases\n");
}

void test_Search() {
    struct BST* RootPtr = NULL;

    Insert(&RootPtr, 5); 
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);

    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 8) == 0);
    assert(Search(RootPtr, 2) == 1);
    assert(Search(RootPtr, 6) == 0);

    printf("Search function passed all test cases\n");
}