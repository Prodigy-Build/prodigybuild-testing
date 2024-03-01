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
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->prev == head);
    assert(head->next->next == NULL);

    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->prev == head);
    assert(head->next->next->value == 1);
    assert(head->next->next->prev == head->next);
    assert(head->next->next->next == NULL);
}

void test_Display() {
    head = NULL;
    Display(); // Nothing to display

    Insert(1);
    Insert(2);
    Insert(3);
    printf("\nExpected Output: 3 2 1\n");
    printf("Actual Output: ");
    Display();
    printf("\n");
}

void test_ReverseDisplay() {
    head = NULL;
    ReverseDisplay(); // Nothing to display

    Insert(1);
    Insert(2);
    Insert(3);
    printf("\nExpected Output: 1 2 3\n");
    printf("Actual Output: ");
    ReverseDisplay();
    printf("\n");
}

int main() {
    test_Insert();
    test_Display();
    test_ReverseDisplay();

    return 0;
}