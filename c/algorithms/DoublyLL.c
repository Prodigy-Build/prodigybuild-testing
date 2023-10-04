```
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

void TestInsert() {
    Insert(1);
    Insert(2);
    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->next->value == 1);
    assert(head->next->next->next == NULL);
}

void TestDisplay() {
    // Manually create a doubly linked list with values 1, 2, 3
    struct Node *node1 = CreateNode();
    node1->value = 1;
    node1->next = NULL;
    node1->prev = NULL;

    struct Node *node2 = CreateNode();
    node2->value = 2;
    node2->next = NULL;
    node2->prev = node1;
    node1->next = node2;

    struct Node *node3 = CreateNode();
    node3->value = 3;
    node3->next = NULL;
    node3->prev = node2;
    node2->next = node3;

    head = node1;

    printf("\nExpected Output:\n");
    printf("1 2 3 \n");

    printf("\nActual Output:\n");
    Display();
}

void TestReverseDisplay() {
    // Manually create a doubly linked list with values 1, 2, 3
    struct Node *node1 = CreateNode();
    node1->value = 1;
    node1->next = NULL;
    node1->prev = NULL;

    struct Node *node2 = CreateNode();
    node2->value = 2;
    node2->next = NULL;
    node2->prev = node1;
    node1->next = node2;

    struct Node *node3 = CreateNode();
    node3->value = 3;
    node3->next = NULL;
    node3->prev = node2;
    node2->next = node3;

    head = node1;

    printf("\nExpected Output:\n");
    printf("3 2 1 \n");

    printf("\nActual Output:\n");
    ReverseDisplay();
}

void main() {
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

    // Run unit tests
    TestInsert();
    TestDisplay();
    TestReverseDisplay();
}
```