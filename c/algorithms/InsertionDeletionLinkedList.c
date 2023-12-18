#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

struct node *CreateNode(int value) {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = value;
    new->next = NULL;
    return new;
}

void InsertAtBegin(int value) {
    struct node *NewNode = CreateNode(value);
    if (head == NULL) {
        head = NewNode;
    } else {
        printf("\n\t**Element already exists at this position**\n");
    }
}

int ListLength() {
    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void InsertAtnthNode(int pos , int value) {
    int length = ListLength();
    if (pos == 1) {
        InsertAtBegin(value);
    } else if (pos <= length + 1) {
        struct node *temp = head;
        struct node *NewNode = CreateNode(value);
        for (int i=1; i<pos-1; i++) {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    } else {
        printf("\n\t**Invalid position to insert at**\n");
    }
}

void InsertAtEnd(int value) {
    struct node *NewNode = CreateNode(value);
    if (head == NULL) {
        head = NewNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}

void DeleteAtBegin() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\n\t**Element deleted successfully**\n");
    } else {
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeletenthNode(int pos) {
    int length = ListLength();
    if (pos == 1) {
        DeleteAtBegin();
    } else if (pos <= length) {
        struct node *temp = head;
        struct node *prev = NULL;
        for (int i=1; i<pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("\n\t**Element deleted successfully**\n");
    } else {
        printf("\n\t**Invalid position to delete at**\n");
    }
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        struct node *temp = head;
        printf("\nCurrent List:\n");
        while (temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void test() {
    head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    InsertAtBegin(3);
    InsertAtnthNode(2, 4);
    InsertAtnthNode(5, 5);
    InsertAtEnd(6);
    InsertAtEnd(7);
    DeleteAtBegin();
    DeleteAtEnd();
    DeletenthNode(2);
    DeletenthNode(4);
    Display();
}

int main() {
    test();
    return 0;
}