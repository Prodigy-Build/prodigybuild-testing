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

void test_Insert() {
    Insert(1);

    assert(head != NULL);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);

    assert(head != NULL);
    assert(head->value == 2);
    assert(head->next != NULL);
    assert(head->prev == NULL);
    assert(head->next->value == 1);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);
}

void test_Display() {
    Insert(1);
    Insert(2);
    Insert(3);

    printf("Expected output: \nForward:\n3 2 1 \n");
    printf("Actual output: \n");
    Display();
    printf("\n");
}

void test_ReverseDisplay() {
    Insert(1);
    Insert(2);
    Insert(3);

    printf("Expected output: \nBackward:\n1 2 3 \n");
    printf("Actual output: \n");
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

    Display();
    ReverseDisplay();

    test_Insert();
    test_Display();
    test_ReverseDisplay();

    return 0;
}