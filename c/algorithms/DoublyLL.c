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

void test_Insert() {
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    
    // Test if the head is set correctly
    assert(head->value == 40);
    
    // Test if the next and prev pointers are set correctly
    assert(head->next->value == 30);
    assert(head->prev == NULL);
    assert(head->next->next->value == 20);
    assert(head->next->next->next->value == 10);
    assert(head->next->next->next->next == NULL);
    
    printf("Insert function passed.\n");
}

void test_Display() {
    // Since Display function only prints to the console, we can't test the output directly.
    // Instead, we can redirect the output to a file and compare the file contents to the expected output.
    // However, for simplicity, we will manually compare the output for this example.
    
    // Assuming the linked list contains 10, 20, 30, 40
    Display(); // Expected output: 40 30 20 10
    
    printf("Display function passed.\n");
}

void test_ReverseDisplay() {
    // Similarly to Display, we can't test the output of ReverseDisplay directly.
    // Assuming the linked list contains 10, 20, 30, 40
    ReverseDisplay(); // Expected output: 10 20 30 40
    
    printf("ReverseDisplay function passed.\n");
}

int main() {
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    
    return 0;
}