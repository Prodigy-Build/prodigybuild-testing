// Implementing Doubly linked list with optimized methods and clean code.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void traverseForward() {
    struct Node *temp = head;
    printf("\nTraversing Forward:\n");
    while(temp != NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward() {
    struct Node *temp = head;
    if (temp == NULL) {
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("\nTraversing Backward:\n");
    while(temp != NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        insertAtHead(val);
    }
    traverseForward();
    traverseBackward();
}