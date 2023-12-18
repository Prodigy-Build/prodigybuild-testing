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

void testInsert()
{
    // Test case 1
    Insert(1);
    assert(head != NULL);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    // Test case 2
    Insert(2);
    assert(head != NULL);
    assert(head->value == 2);
    assert(head->next != NULL);
    assert(head->prev == NULL);
    assert(head->next->value == 1);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);

    printf("Insert() passed all test cases.\n");
}

void testDisplay()
{
    // Test case 1
    head = NULL;
    printf("Forward:\n");
    Display();
    printf("\nExpected: \n");

    // Test case 2
    Insert(1);
    head = NULL;
    printf("Forward:\n");
    Display();
    printf("\nExpected: 1 \n");

    // Test case 3
    Insert(1);
    Insert(2);
    head = NULL;
    printf("Forward:\n");
    Display();
    printf("\nExpected: 2 1 \n");

    printf("Display() passed all test cases.\n");
}

void testReverseDisplay()
{
    // Test case 1
    head = NULL;
    printf("Backward:\n");
    ReverseDisplay();
    printf("\nExpected: \n");

    // Test case 2
    Insert(1);
    head = NULL;
    printf("Backward:\n");
    ReverseDisplay();
    printf("\nExpected: 1 \n");

    // Test case 3
    Insert(1);
    Insert(2);
    head = NULL;
    printf("Backward:\n");
    ReverseDisplay();
    printf("\nExpected: 1 2 \n");

    printf("ReverseDisplay() passed all test cases.\n");
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

    // Run tests
    testInsert();
    testDisplay();
    testReverseDisplay();

    return 0;
}