// Unit tests required for these methods
#include <assert.h>
#include <stdio.h>

void testCreateNode() {
    struct Node *node = CreateNode();
    assert(node->value == 0);
    assert(node->next == NULL);
    assert(node->prev == NULL);
}

void testInsert() {
    Insert(10);
    assert(head->value == 10);
    assert(head->next == NULL);
    assert(head->prev == NULL);
    
    Insert(20);
    assert(head->value == 20);
    assert(head->next->value == 10);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);
}

void testDisplay() {
    struct Node *temp = head;
    assert(temp->value == 20);
    assert(temp->next->value == 10);
    assert(temp->next->next == NULL);
}

void testReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    assert(temp->value == 10);
    assert(temp->prev->value == 20);
    assert(temp->prev->prev == NULL);
}

int main() {
    testCreateNode();
    testInsert();
    testDisplay();
    testReverseDisplay();
    printf("All tests passed!\n");
    return 0;
}