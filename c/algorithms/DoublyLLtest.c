#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *CreateNode() {
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    return new;
}

void Insert(int val) {
    struct Node *NewNode = CreateNode();
    NewNode->value = val;
    NewNode->next = head;
    NewNode->prev = NULL;
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n");
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }

    printf("\nBackward:\n");
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void test_Insert() {
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->prev == head);
    assert(head->prev == NULL);

    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->prev == head);
    assert(head->next->next->value == 1);
    assert(head->next->next->prev == head->next);
    assert(head->prev == NULL);
}

void test_Display() {
    // Prepare test data
    Insert(1);
    Insert(2);
    Insert(3);

    // Test Display
    printf("\nDisplay Test:\n");
    Display();
    printf("\n");
}

void test_ReverseDisplay() {
    // Prepare test data
    Insert(1);
    Insert(2);
    Insert(3);

    // Test ReverseDisplay
    printf("\nReverseDisplay Test:\n");
    ReverseDisplay();
    printf("\n");
}

int main() {
    // Run unit tests
    test_Insert();
    test_Display();
    test_ReverseDisplay();

    return 0;
}