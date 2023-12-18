#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Unit test cases
void testInsert() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 5);
    assert(RootPtr->data == 5);

    Insert(&RootPtr, 3);
    assert(RootPtr->left->data == 3);

    Insert(&RootPtr, 7);
    assert(RootPtr->right->data == 7);

    Insert(&RootPtr, 2);
    assert(RootPtr->left->left->data == 2);

    Insert(&RootPtr, 4);
    assert(RootPtr->left->right->data == 4);

    Insert(&RootPtr, 6);
    assert(RootPtr->right->left->data == 6);

    Insert(&RootPtr, 8);
    assert(RootPtr->right->right->data == 8);
}

void testSearch() {
    struct BST* RootPtr = NULL;
    Insert(&RootPtr, 5);
    Insert(&RootPtr, 3);
    Insert(&RootPtr, 7);
    Insert(&RootPtr, 2);
    Insert(&RootPtr, 4);
    Insert(&RootPtr, 6);
    Insert(&RootPtr, 8);

    assert(Search(RootPtr, 1) == 0);
    assert(Search(RootPtr, 2) == 1);
    assert(Search(RootPtr, 3) == 1);
    assert(Search(RootPtr, 4) == 1);
    assert(Search(RootPtr, 5) == 1);
    assert(Search(RootPtr, 6) == 1);
    assert(Search(RootPtr, 7) == 1);
    assert(Search(RootPtr, 8) == 1);
    assert(Search(RootPtr, 9) == 0);
}

int main() {
    testInsert();
    testSearch();
    return 0;
}