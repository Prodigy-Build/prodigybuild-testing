#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;

struct Node *CreateNode() {
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    return new;
}

void Insert(int val) {
    struct Node *newNode = CreateNode();
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

void Test_Insert() {
    head = NULL;
    Insert(3);
    assert(head->value == 3);
    Insert(5);
    assert(head->value == 5);
    assert(head->next->value == 3);
}

void Test_Display() {
    head = NULL;
    Insert(3);
    Insert(5);
    printf("\nExpected Output:\nForward:\n5 3\n");
    printf("Output:\n");
    Display();
}

void Test_ReverseDisplay() {
    head = NULL;
    Insert(3);
    Insert(5);
    printf("\nExpected Output:\nBackward:\n3 5\n");
    printf("Output:\n");
    ReverseDisplay();
}

int main() {
    Test_Insert();
    Test_Display();
    Test_ReverseDisplay();
    return 0;
}