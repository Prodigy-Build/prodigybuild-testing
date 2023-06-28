



// DoublyLL_28thJune.c
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Unit test
int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printList(head);
    deleteNode(&head, 30);
    printList(head);
    return 0;
}