// Refactored code for the doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *CreateNode(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Insert(struct Node **head, int val) {
    struct Node *newNode = CreateNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void Display(struct Node *head) {
    struct Node *temp = head;
    printf("\nForward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay(struct Node *head) {
    struct Node *temp = head;
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
    struct Node *head = NULL;
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        Insert(&head, val);
    }
    Display(head);
    ReverseDisplay(head);
    
    return 0;
}