// Implementing Doubly linked list.
#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"

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

// Unit tests

TEST(DoublyLinkedList, Insert) {
    Insert(1);
    Insert(2);
    Insert(3);
    
    struct Node *temp = head;
    
    EXPECT_EQ(temp->value, 3);
    temp = temp->next;
    EXPECT_EQ(temp->value, 2);
    temp = temp->next;
    EXPECT_EQ(temp->value, 1);
    temp = temp->next;
    
    EXPECT_EQ(temp, NULL);
}

TEST(DoublyLinkedList, Display) {
    Insert(1);
    Insert(2);
    Insert(3);
    
    testing::internal::CaptureStdout();
    Display();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "\nForward:\n3 2 1 ");
}

TEST(DoublyLinkedList, ReverseDisplay) {
    Insert(1);
    Insert(2);
    Insert(3);
    
    testing::internal::CaptureStdout();
    ReverseDisplay();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "\nBackward:\n1 2 3 \n");
}