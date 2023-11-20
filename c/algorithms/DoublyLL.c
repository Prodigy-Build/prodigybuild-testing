```c
// Implementing Doubly linked list.
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

void Insert(int val) { /*Inserting element at head*/
    struct Node *NewNode = CreateNode(); /*NewNode is created everytime function is called*/
    NewNode->value = val; /*Value assigned to NewNode*/
    NewNode->next = head; /*NewNode's next points to head*/
    NewNode->prev = NULL; /*NewNode's previous points to NULL*/
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n"); /*Printing normally in forward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) { /*Moving to the last node*/
        temp = temp->next;
    }

    printf("\nBackward:\n"); /*Printing in backward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void test() {
    // Test case 1
    Insert(10);
    assert(head->value == 10);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    // Test case 2
    Insert(20);
    assert(head->value == 20);
    assert(head->next->value == 10);
    assert(head->prev == NULL);
    assert(head->next->prev == head);

    // Test case 3
    Insert(30);
    assert(head->value == 30);
    assert(head->next->value == 20);
    assert(head->prev == NULL);
    assert(head->next->prev == head);

    Display();
    ReverseDisplay();
}

int main() {
    test();
    return 0;
}
```