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

void Insert(int val) {
    struct Node *NewNode = CreateNode();
    NewNode->value = val;
    NewNode->next = head;
    NewNode->prev = NULL;
    if (head != NULL) {
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n");
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }

    printf("\nBackward:\n");
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void testInsert() {
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    assert(head->value == 5);
    assert(head->next->value == 4);
    assert(head->next->next->value == 3);
    assert(head->next->next->next->value == 2);
    assert(head->next->next->next->next->value == 1);
    assert(head->next->next->next->next->next == NULL);
    assert(head->next->next->next->next->prev->value == 2);
    assert(head->prev == NULL);
    assert(head->next->prev->value == 3);
    printf("Insert test passed.\n");
}

void testDisplay() {
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    printf("Expected Output: Forward:\n5 4 3 2 1\n");
    printf("Actual Output: ");
    Display();
    printf("\n");
}

void testReverseDisplay() {
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    printf("Expected Output: Backward:\n1 2 3 4 5\n");
    printf("Actual Output: ");
    ReverseDisplay();
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val);
    }

    testInsert();
    testDisplay();
    testReverseDisplay();

    return 0;
}