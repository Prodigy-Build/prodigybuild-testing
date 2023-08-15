

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

void Insert(int val) { /*Inserting element at head*/
    struct Node *NewNode = CreateNode(); /*NewNode is created everytime function is called*/
    NewNode->value = val; /*Value assigned to NewNode*/
    NewNode->next = head; /*NewNode's next points to head*/
    NewNode->prev = NULL; /*NewNode's previous points to NULL*/
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n"); /*Printing normally in forward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) { /*Moving to the last node*/
        temp = temp->next;
    }

    printf("\nBackward:\n"); /*Printing in backward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val); /*Inserting value everytime loop executes*/
    }
    Display();
    ReverseDisplay();
}

// Unit Test Cases
void test_CreateNode() {
    struct Node *node = CreateNode();
    assert(node != NULL);
    free(node);
}

void test_Insert() {
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);
}

void test_Display() {
    Insert(2);
    Insert(3);
    Insert(4);
    Display();
    assert(head->value == 4);
    assert(head->next->value == 3);
    assert(head->next->next->value == 2);
    assert(head->next->next->next == NULL);
}

void test_ReverseDisplay() {
    ReverseDisplay();
    assert(head->value == 4);
    assert(head->prev->value == 3);
    assert(head->prev->prev->value == 2);
    assert(head->prev->prev->prev == NULL);
}

int main() {
    test_CreateNode();
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    return 0;
}