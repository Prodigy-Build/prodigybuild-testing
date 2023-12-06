#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *CreateNode(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Insert(int val) {
    struct Node *newNode = CreateNode(val);
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
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
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        Insert(val);
    }
    Display();
    ReverseDisplay();

    return 0;
}