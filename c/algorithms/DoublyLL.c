// Refactoring the code
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head;

Node *createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int value) {
    Node *newNode = createNode(value);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void displayForward() {
    Node *temp = head;
    printf("\nForward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void displayBackward() {
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("\nBackward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &value);
        insertAtHead(value);
    }
    displayForward();
    displayBackward();

    return 0;
}