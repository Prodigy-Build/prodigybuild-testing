#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define the struct for the linked list node
struct node {
    int data;
    struct node* next;
};
struct node* head;

// Create a new node
struct node* CreateNode() {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    return new;
}

// Insert a node at the beginning of the linked list
void InsertAtBegin(int value) {
    struct node* NewNode = CreateNode();
    if (head == NULL) {
        NewNode->data = value;
        head = NewNode;
        NewNode->next = NULL;
    } else {
        printf("\n\t**Element already exists at this position**\n");
    }
}

// Insert a node at the nth position in the linked list
void InsertAtnthNode(int pos, int value) {
    struct node* temp = head;
    if (pos == 1) {
        printf("\n\t**Use Insert at beginning**\n");
    } else {
        struct node* NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = NULL;
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

// Insert a node at the end of the linked list
void InsertAtEnd(int value) {
    if (head == NULL) {
        printf("\n\t**Use Insert at beginning**\n");
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        struct node* NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

// Delete the node at the beginning of the linked list
void DeleteAtBegin() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else {
        head = head->next;
        printf("\n\t**Element deleted successfully**\n");
    }
}

// Delete the node at the end of the linked list
void DeleteAtEnd() {
    if (head == NULL) {
        printf("\n\t**No element exists**\n");
    } else if (head->next == NULL) {
        printf("\n\t**Use Delete at beginning**\n");
    } else {
        struct node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
        printf("\n\t**Element deleted successfully**\n");
    }
}

// Delete the node at the nth position in the linked list
void DeletenthNode(int pos) {
    struct node* temp = head;
    if (pos == 1) {
        printf("\n\t**Use Delete at beginning**\n");
    } else {
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
        }
        struct node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        printf("\n\t**Element deleted successfully**\n");
    }
}

// Display the elements in the linked list
void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        struct node* temp = head;
        printf("\nCurrent List:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

// Unit test cases

void test_InsertAtBegin() {
    head = NULL;
    InsertAtBegin(5);
    assert(head->data == 5);
    InsertAtBegin(10);
    assert(head->data == 10);
    printf("InsertAtBegin test passed\n");
}

void test_InsertAtnthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtnthNode(2, 30);
    struct node* temp = head;
    int count = 1;
    while (temp != NULL) {
        if (count == 2) {
            assert(temp->data == 30);
        } else {
            assert(temp->data != 30);
        }
        temp = temp->next;
        count++;
    }
    printf("InsertAtnthNode test passed\n");
}

void test_InsertAtEnd() {
    head = NULL;
    InsertAtEnd(10);
    assert(head->data == 10);
    InsertAtEnd(20);
    assert(head->next->data == 20);
    printf("InsertAtEnd test passed\n");
}

void test_DeleteAtBegin() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtBegin();
    assert(head->data == 10);
    DeleteAtBegin();
    assert(head == NULL);
    printf("DeleteAtBegin test passed\n");
}

void test_DeleteAtEnd() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtEnd();
    assert(head->data == 20);
    DeleteAtEnd();
    assert(head == NULL);
    printf("DeleteAtEnd test passed\n");
}

void test_DeletenthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeletenthNode(2);
    struct node* temp = head;
    int count = 1;
    while (temp != NULL) {
        if (count == 2) {
            assert(temp->data != 20);
        }
        temp = temp->next;
        count++;
    }
    printf("DeletenthNode test passed\n");
}

int main() {
    head = NULL;
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    return 0;
}