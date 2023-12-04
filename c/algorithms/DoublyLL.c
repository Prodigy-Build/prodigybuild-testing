```
// Refactored version of the code

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
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void DisplayForward() {
    struct Node *temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void DisplayBackward() {
    struct Node *temp = head;
    if(temp == NULL) {
        printf("Backward: ");
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward: ");
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

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        Insert(val);
    }
    
    DisplayForward();
    DisplayBackward();

    return 0;
}
```