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

void testInsert() {
    head = NULL;
    Insert(5);
    assert(head->value == 5);
    Insert(10);
    assert(head->value == 10);
    assert(head->next->value == 5);
}

void testDisplay() {
    // Initialize head with test values
    head = CreateNode();
    head->value = 5;
    head->next = CreateNode();
    head->next->value = 10;

    printf("\nExpected Output:\n5 10\n");
    printf("Actual Output:\n");
    Display();
}

void testReverseDisplay() {
    // Initialize head with test values
    head = CreateNode();
    head->value = 5;
    head->prev = NULL;
    head->next = CreateNode();
    head->next->value = 10;
    head->next->prev = head;

    printf("\nExpected Output:\n10 5\n");
    printf("Actual Output:\n");
    ReverseDisplay();
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        Insert(val); /*Inserting value everytime loop executes*/
    }
    Display();
    ReverseDisplay();

    // Run unit test cases
    testInsert();
    testDisplay();
    testReverseDisplay();

    return 0;
}