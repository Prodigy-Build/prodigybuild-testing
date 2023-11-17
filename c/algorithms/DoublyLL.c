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

void unit_tests() {
    // Test 1: Inserting elements
    Insert(1);
    Insert(2);
    Insert(3);
    
    // Test 2: Displaying elements
    printf("\nExpected Output: Forward:\n3 2 1\n");
    printf("Actual Output: ");
    Display();
    
    // Test 3: Displaying elements in reverse
    printf("\nExpected Output: Backward:\n1 2 3\n");
    printf("Actual Output: ");
    ReverseDisplay();
}

int main() {
    unit_tests();
    return 0;
}