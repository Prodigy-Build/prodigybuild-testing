```C
// Implementing Doubly linked list with binary search.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *CreateNode(int val) {
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new->value = val; 
    return new;
}

void Insert(int val) {
    struct Node *NewNode = CreateNode(val);
    NewNode->next = head;
    NewNode->prev = NULL;
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void BinSearch(int element) {
    struct Node *temp = head;
    while(temp != NULL) {
        if(temp->value == element) {
            printf("Element found : %d\n", element);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found : %d\n", element);
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

int main() {
    int n, val, element;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val);
    }

    printf("Enter element to be searched: ");
    scanf("%d",&element);
    BinSearch(element);
    Display();
    ReverseDisplay();
    return 0;
}
```