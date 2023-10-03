```c/algorithms/InsertionDeletionLinkedList.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

struct node *CreateNode() {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    return new;
}

void InsertAtBegin(int value) {
    struct node *NewNode = CreateNode();
    if (head == NULL) { 
        NewNode->data = value;
        head = NewNode;
        NewNode->next = NULL;
    } else {
        printf("\n\t**Element already exists at this position**\n");
    }
}

void InsertAtnthNode(int pos , int value) {
    struct node* temp = head;
    if(pos==1) {
        printf("\n\t**Use Insert at begining**\n");
    } else { 
        struct node *NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = NULL;
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void InsertAtEnd(int value) {
    if (head == NULL) {
        printf("\n\t**Use Insert at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        struct node *NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void DeleteAtBegin() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else {
        head = head->next;
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else if (head->next == NULL) {
        printf("\n\t**Use Delete at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next->next!=NULL) { 
            temp = temp->next;
        }
        temp->next = NULL; 
        free(temp->next);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeletenthNode(int pos) {
    struct node *temp = head;
    if (pos == 1) {
        printf("\n\t**Use Delete at begining**\n");
    } else {
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        struct node *temp = head;
        printf("\nCurrent List:\n");
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

// Unit Tests

void test_InsertAtBegin() {
    InsertAtBegin(10);
    assert(head->data == 10);
    assert(head->next == NULL);
    InsertAtBegin(20);
    assert(head->data == 20);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
}

void test_InsertAtnthNode() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    InsertAtnthNode(2, 40);
    assert(head->data == 30);
    assert(head->next->data == 40);
    assert(head->next->next->data == 20);
    assert(head->next->next->next->data == 10);
    assert(head->next->next->next->next == NULL);
}

void test_InsertAtEnd() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    InsertAtEnd(40);
    assert(head->data == 30);
    assert(head->next->data == 20);
    assert(head->next->next->data == 10);
    assert(head->next->next->next->data == 40);
    assert(head->next->next->next->next == NULL);
}

void test_DeleteAtBegin() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtBegin();
    assert(head->data == 10);
    assert(head->next == NULL);
    DeleteAtBegin();
    assert(head == NULL);
}

void test_DeleteAtEnd() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeleteAtEnd();
    assert(head->data == 30);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    DeleteAtEnd();
    assert(head->data == 30);
    assert(head->next == NULL);
    DeleteAtEnd();
    assert(head == NULL);
}

void test_DeletenthNode() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    InsertAtBegin(40);
    DeletenthNode(2);
    assert(head->data == 40);
    assert(head->next->data == 30);
    assert(head->next->next->data == 10);
    assert(head->next->next->next == NULL);
    DeletenthNode(1);
    assert(head->data == 30);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
    DeletenthNode(2);
    assert(head->data == 30);
    assert(head->next == NULL);
}

void test_Display() {
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    Display();
    InsertAtBegin(40);
    InsertAtEnd(50);
    Display();
}

int main() {
    head = NULL;
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    test_Display();
    return 0;
}
```