#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* CreateNode(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void Insert(int val) { /*Inserting element at head*/
    struct Node* new_node = CreateNode(val);
    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    head = new_node;
}

void Display() {
    struct Node* temp = head;
    printf("\nForward:\n"); /*Printing normally in forward manner*/
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node* temp = head;
    while (temp->next != NULL) { /*Moving to the last node*/
        temp = temp->next;
    }

    printf("\nBackward:\n"); /*Printing in backward manner*/
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
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
    return 0;
}