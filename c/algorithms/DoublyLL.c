#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Structure for Doubly Linked List Node
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

// Global variable for head of Doubly Linked List
struct Node* head;

// Function to create a new node
// Returns new node with value initialized
struct Node* CreateNode() {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    return new;
}

// Function to insert a new node at the head of Doubly Linked List
void Insert(int val) {
    struct Node* NewNode = CreateNode();
    NewNode->value = val;
    NewNode->next = head;
    NewNode->prev = NULL;
    if (head != NULL) {
        head->prev = NewNode;
    }
    head = NewNode;
}

// Function to display the elements of Doubly Linked List in forward order
void Display() {
    struct Node* temp = head;
    printf("\nForward:\n");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

// Function to display the elements of Doubly Linked List in reverse order
void ReverseDisplay() {
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nBackward:\n");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to test Insert function
void testInsert() {
    head = NULL;

    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->prev == NULL);

    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->prev == NULL);
    assert(head->next->next->value == 1);
    assert(head->next->next->prev->value == 2);
    assert(head->next->next->prev->prev->value == 3);
    assert(head->next->next->prev->prev->prev == NULL);
}

// Function to test Display and ReverseDisplay functions
void testDisplay() {
    head = NULL;

    Display();

    ReverseDisplay();

    Insert(1);
    Insert(2);
    Insert(3);

    Display();

    ReverseDisplay();
}

// Main function
int main() {
    // Run unit tests
    testInsert();
    testDisplay();

    return 0;
}