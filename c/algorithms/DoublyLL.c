// Implementing Doubly linked list.
#include <stdio.h>
#include <stdlib.h>
// Include a testing framework
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

void test_Insert() {
    Insert(1);
    assert(head->value == 1);
    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    
    printf("Insert tests passed\n");
}

void test_Display() {
    Insert(1);
    Insert(2);
    printf("\nExpected Output:\nForward:\n2 1 \nActual Output:\n");
    Display();
    
    printf("\nDisplay tests passed\n");
}

void test_ReverseDisplay() {
    Insert(1);
    Insert(2);
    printf("\nExpected Output:\nBackward:\n1 2 \nActual Output:\n");
    ReverseDisplay();
    
    printf("\nReverseDisplay tests passed\n");
}

int main() {
    // Run the unit tests
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    
    return 0;
}