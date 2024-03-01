#include <stdio.h>
#include <stdlib.h>

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
    // Test case 1
    Insert(5);
    Insert(10);
    Insert(15);
    Insert(20);
    Insert(25);
    Display(); // Expected output: 25 20 15 10 5
    ReverseDisplay(); // Expected output: 5 10 15 20 25

    // Test case 2
    Insert(30);
    Insert(35);
    Insert(40);
    Display(); // Expected output: 40 35 30 25 20 15 10 5
    ReverseDisplay(); // Expected output: 5 10 15 20 25 30 35 40
}

int main() {
    test_Insert();
    return 0;
}