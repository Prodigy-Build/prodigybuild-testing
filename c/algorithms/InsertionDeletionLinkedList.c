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

// Unit tests

void test_InsertAtBegin() {
    head = NULL;
    
    InsertAtBegin(10);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    
    InsertAtBegin(20);
    assert(head != NULL);
    assert(head->data == 20);
    assert(head->next != NULL);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
}

void test_InsertAtnthNode() {
    head = NULL;
    
    InsertAtnthNode(1, 10);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    
    InsertAtnthNode(2, 20);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    
    InsertAtnthNode(2, 30);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next != NULL);
    assert(head->next->data == 30);
    assert(head->next->next != NULL);
    assert(head->next->next->data == 20);
    assert(head->next->next->next == NULL);
}

void test_InsertAtEnd() {
    head = NULL;
    
    InsertAtEnd(10);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    
    InsertAtEnd(20);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    
    InsertAtEnd(30);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    assert(head->next->next != NULL);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
}

void test_DeleteAtBegin() {
    head = NULL;
    
    InsertAtBegin(10);
    InsertAtBegin(20);
    
    DeleteAtBegin();
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    
    DeleteAtBegin();
    assert(head == NULL);
}

void test_DeleteAtEnd() {
    head = NULL;
    
    InsertAtBegin(10);
    InsertAtBegin(20);
    
    DeleteAtEnd();
    assert(head != NULL);
    assert(head->data == 20);
    assert(head->next == NULL);
    
    DeleteAtEnd();
    assert(head == NULL);
}

void test_DeletenthNode() {
    head = NULL;
    
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    
    DeletenthNode(2);
    assert(head != NULL);
    assert(head->data == 30);
    assert(head->next != NULL);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
    
    DeletenthNode(1);
    assert(head != NULL);
    assert(head->data == 10);
    assert(head->next == NULL);
    
    DeletenthNode(1);
    assert(head == NULL);
}

void test_Display() {
    head = NULL;
    
    Display(); // No elements to display
    
    InsertAtBegin(10);
    
    printf("\nExpected Output: \nCurrent List:\n10 \n");
    printf("Actual Output: \n");
    Display();
    
    InsertAtBegin(20);
    
    printf("\nExpected Output: \nCurrent List:\n20 10 \n");
    printf("Actual Output: \n");
    Display();
}

int main() {
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    test_Display();
    
    printf("\n\t**All test cases passed**\n");
    
    return 0;
}