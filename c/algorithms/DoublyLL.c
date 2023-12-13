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

void test_InsertAndDisplay() {
    Insert(5);
    Insert(10);
    Insert(15);

    printf("Expected Output: Forward:\n15 10 5 \n");
    Display();
    printf("\n");

    printf("Expected Output: Backward:\n5 10 15 \n");
    ReverseDisplay();
    printf("\n");
}

void test_ReverseDisplay() {
    Insert(5);
    Insert(10);
    Insert(15);

    printf("Expected Output: Backward:\n5 10 15 \n");
    ReverseDisplay();
    printf("\n");
}

int main() {
    test_InsertAndDisplay();
    test_ReverseDisplay();

    return 0;
}