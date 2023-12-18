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
        printf("\n\t**Use Insert at beginning**\n");
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
        printf("\n\t**Use Delete at beginning**\n");
    } else {
        struct node *temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=NULL;
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
    InsertAtBegin(10);
    assert(head->data == 10);
    printf("InsertAtBegin() test passed.\n");
}

void testInsertAtnthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    InsertAtnthNode(2, 15);
    struct node *temp = head;
    if (temp->next->data != 15) {
        printf("InsertAtnthNode() test failed.\n");
        return;
    }
    temp = temp->next;
    if (temp->next->data != 20) {
        printf("InsertAtnthNode() test failed.\n");
        return;
    }
    temp = temp->next;
    if (temp->next->data != 10) {
        printf("InsertAtnthNode() test failed.\n");
        return;
    }
    printf("InsertAtnthNode() test passed.\n");
}

void testInsertAtEnd() {
    head = NULL;
    InsertAtEnd(10);
    assert(head->data == 10);
    printf("InsertAtEnd() test passed.\n");
}

void testDeleteAtBegin() {
    head = NULL;
    DeleteAtBegin();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtBegin();
    assert(head->data == 10);
    printf("DeleteAtBegin() test passed.\n");
}

void testDeleteAtEnd() {
    head = NULL;
    DeleteAtEnd();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtEnd();
    assert(head->data == 20);
    printf("DeleteAtEnd() test passed.\n");
}

void testDeletenthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeletenthNode(2);
    struct node *temp = head;
    if (temp->data != 30) {
        printf("DeletenthNode() test failed.\n");
        return;
    }
    temp = temp->next;
    if (temp->data != 10) {
        printf("DeletenthNode() test failed.\n");
        return;
    }
    printf("DeletenthNode() test passed.\n");
}

int main() {
    testInsertAtBegin();
    testInsertAtnthNode();
    testInsertAtEnd();
    testDeleteAtBegin();
    testDeleteAtEnd();
    testDeletenthNode();
    return 0;
}