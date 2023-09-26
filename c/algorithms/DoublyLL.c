#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

void Insert(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
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

void testInsert() {
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->prev == head);
}

void testDisplay() {
    printf("Testing Display...\n");
    Insert(1);
    Insert(2);
    printf("Expected Output: \nForward:\n2 1\n");
    printf("Output: ");
    Display();
}

void testReverseDisplay() {
    printf("Testing ReverseDisplay...\n");
    Insert(1);
    Insert(2);
    printf("Expected Output: \nBackward:\n1 2\n");
    printf("Output: ");
    ReverseDisplay();
}

int main() {
    testInsert();
    testDisplay();
    testReverseDisplay();

    return 0;
}