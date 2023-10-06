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

void testInsertAtBegin() {
    head = NULL;
    InsertAtBegin(5);
    assert(head->data == 5);
    head = NULL;
    InsertAtBegin(10);
    assert(head->data == 10);
}

void testInsertAtnthNode() {
    head = NULL;
    InsertAtnthNode(2, 5);
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtnthNode(1, 15);
    assert(head->next->data == 10);
    InsertAtnthNode(2, 20);
    assert(head->next->data == 20);
}

void testInsertAtEnd() {
    head = NULL;
    InsertAtEnd(5);
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtEnd(15);
    assert(head->next->data == 15);
    InsertAtEnd(20);
    assert(head->next->next->data == 20);
}

void testDeleteAtBegin() {
    head = NULL;
    DeleteAtBegin();
    assert(head == NULL);
    InsertAtBegin(5);
    DeleteAtBegin();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(15);
    DeleteAtBegin();
    assert(head->data == 10);
}

void testDeleteAtEnd() {
    head = NULL;
    DeleteAtEnd();
    assert(head == NULL);
    InsertAtBegin(5);
    DeleteAtEnd();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(15);
    DeleteAtEnd();
    assert(head->data == 15);
}

void testDeletenthNode() {
    head = NULL;
    DeletenthNode(2);
    assert(head == NULL);
    InsertAtBegin(10);
    DeletenthNode(1);
    assert(head->data == 10);
    InsertAtBegin(15);
    InsertAtBegin(20);
    DeletenthNode(2);
    assert(head->next->data == 10);
}

int main() {
    head = NULL;
    testInsertAtBegin();
    testInsertAtnthNode();
    testInsertAtEnd();
    testDeleteAtBegin();
    testDeleteAtEnd();
    testDeletenthNode();
    printf("\n\t**All Test Cases Passed**\n");
    return 0;
}