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
    assert(head != NULL);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head != NULL);
    assert(head->value == 2);
    assert(head->next != NULL);
    assert(head->next->prev == head);
}

void test_Display() {
    struct Node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        Insert(temp->value);
    }
    printf("\nForward:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
    }
}

void test_ReverseDisplay() {
    struct Node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        Insert(temp->value);
    }
    printf("\nBackward:\n");
    for (int i = 2; i >= 0; i--) {
        printf("%d ", i + 1);
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val); /*Inserting value everytime loop executes*/
    }
    Display();
    ReverseDisplay();

    test_Insert();
    test_Display();
    test_ReverseDisplay();

    return 0;
}