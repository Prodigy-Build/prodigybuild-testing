// Refactored code

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

Node *CreateNode(int val) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

void Insert(int val) { 
    Node *newNode = CreateNode(val); 

    if (head == NULL) { 
        head = newNode;
        return;
    }

    newNode->next = head; 
    head->prev = newNode; 
    head = newNode;
}

void Display() {
    Node *temp = head;
    printf("\nForward:\n"); 

    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
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
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i=0; i<n; ++i) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val); 
    }
    Display();
    ReverseDisplay();

    return 0;
}