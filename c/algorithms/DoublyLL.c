```c
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
    // Test case 1
    head = NULL;
    Insert(1);
    assert(head != NULL);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);
    
    // Test case 2
    head = NULL;
    Insert(2);
    assert(head != NULL);
    assert(head->value == 2);
    assert(head->next == NULL);
    assert(head->prev == NULL);
    Insert(3);
    assert(head != NULL);
    assert(head->value == 3);
    assert(head->next != NULL);
    assert(head->prev == NULL);
    assert(head->next->value == 2);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);
}

int main() {
    test_Insert();
    Display();
    ReverseDisplay();
    return 0;
}
```