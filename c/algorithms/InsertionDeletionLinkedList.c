#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

struct node *CreateNode() {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    return new;
}

void InsertAtBegin(int value) {
    assert(head == NULL);
    
    struct node *NewNode = CreateNode();
    NewNode->data = value;
    head = NewNode;
    NewNode->next = NULL;

    // Test InsertAtBegin
    assert(head->data == value);
}

void InsertAtnthNode(int pos, int value) {
    assert(head != NULL);
    assert(pos > 1);

    struct node* temp = head;
    struct node *NewNode = CreateNode();
    NewNode->data = value;
    NewNode->next = NULL;

    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;

    // Test InsertAtnthNode
    assert(temp->next->data == value);
}

void InsertAtEnd(int value) {
    assert(head != NULL);

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct node *NewNode = CreateNode();
    NewNode->data = value;
    NewNode->next = temp->next;
    temp->next = NewNode;

    // Test InsertAtEnd
    assert(temp->next->data == value);
}

void DeleteAtBegin() {
    assert(head != NULL);

    head = head->next;

    // Test DeleteAtBegin
    assert(head != NULL);
}

void DeleteAtEnd() {
    assert(head != NULL);

    if (head->next == NULL) {
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    // Test DeleteAtEnd
    assert(head != NULL);
}

void DeletenthNode(int pos) {
    assert(head != NULL);
    assert(pos > 1);

    struct node *temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

    // Test DeletenthNode
    assert(temp->next == NULL);
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        struct node *temp = head;
        printf("\nCurrent List:\n");
        while (temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void test() {
    head = NULL;

    InsertAtBegin(5);
    InsertAtBegin(4);
    InsertAtBegin(3);
    InsertAtBegin(2);
    InsertAtBegin(1);
    Display();

    InsertAtnthNode(3, 10);
    Display();

    InsertAtnthNode(8, 15);
    Display();

    InsertAtEnd(20);
    Display();

    DeleteAtBegin();
    Display();

    DeleteAtEnd();
    Display();

    DeletenthNode(3);
    Display();
}

void main() {
    test();
}