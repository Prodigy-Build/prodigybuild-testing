// Unit test cases for doubly linked list implementation

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
    Insert(10);
    Insert(20);
    Insert(30);
    assert(head->value == 30);
    assert(head->next->value == 20);
    assert(head->next->next->value == 10);
    assert(head->next->next->next == NULL);
}

void test_Display() {
    // Test case 1: Empty list
    head = NULL;
    printf("\nExpected Output for Display (Empty List):\n");
    printf("Forward:\n");

    printf("\nActual Output for Display (Empty List):\n");
    Display();

    // Test case 2: List with elements
    Insert(10);
    Insert(20);
    Insert(30);

    printf("\nExpected Output for Display (List with elements):\n");
    printf("Forward:\n");
    printf("30 20 10 ");

    printf("\nActual Output for Display (List with elements):\n");
    Display();
}

void test_ReverseDisplay() {
    // Test case 1: Empty list
    head = NULL;
    printf("\nExpected Output for ReverseDisplay (Empty List):\n");
    printf("Backward:\n");

    printf("\nActual Output for ReverseDisplay (Empty List):\n");
    ReverseDisplay();

    // Test case 2: List with elements
    Insert(10);
    Insert(20);
    Insert(30);

    printf("\nExpected Output for ReverseDisplay (List with elements):\n");
    printf("Backward:\n");
    printf("10 20 30 ");

    printf("\nActual Output for ReverseDisplay (List with elements):\n");
    ReverseDisplay();
}

int main() {
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    return 0;
}