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

void test_insertAtBegin()
{
    InsertAtBegin(1);
    assert(head->data == 1);
    assert(head->next == NULL);
    InsertAtBegin(2);
    InsertAtBegin(3);
    assert(head->data == 3);
    assert(head->next->next->data == 1);
}

void test_insertAtnthNode()
{
    InsertAtnthNode(1, 4);
    assert(head->data == 3);
    assert(head->next->data == 4);
    InsertAtnthNode(2, 5);
    assert(head->next->next->data == 5);
    assert(head->next->next->next->data == 1);
}

void test_insertAtEnd()
{
    InsertAtEnd(6);
    assert(head->data == 3);
    assert(head->next->data == 4);
    assert(head->next->next->data == 5);
    assert(head->next->next->next->data == 1);
    assert(head->next->next->next->next->data == 6);
}

void test_deleteAtBegin()
{
    DeleteAtBegin();
    assert(head->data == 4);
    assert(head->next->data == 5);
    assert(head->next->next->data == 1);
    assert(head->next->next->next->data == 6);
    DeleteAtBegin();
    DeleteAtBegin();
    assert(head->data == 1);
    assert(head->next->data == 6);
}

void test_deleteAtEnd()
{
    DeleteAtEnd();
    assert(head->data == 1);
    assert(head->next->data == 6);
    assert(head->next->next == NULL);
    InsertAtEnd(7);
    DeleteAtEnd();
    assert(head->data == 1);
    assert(head->next == NULL);
}

void test_deleteNthNode()
{
    DeletenthNode(1);
    assert(head->data == 6);
    InsertAtnthNode(1, 8);
    InsertAtnthNode(2, 9);
    DeletenthNode(2);
    assert(head->next->data == 8);
    assert(head->next->next->data == 6);
}

int main() {
    head = NULL;
    test_insertAtBegin();
    test_insertAtnthNode();
    test_insertAtEnd();
    test_deleteAtBegin();
    test_deleteAtEnd();
    test_deleteNthNode();
    return 0;
}