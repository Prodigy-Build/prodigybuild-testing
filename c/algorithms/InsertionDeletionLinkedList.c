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

int main() {
    head = NULL;
    int ch;
    while (1) {
        printf("\n\t\t**MENU**\n\t1. Insert at begining\n\t2. Insert at nth position\n\t3. Insert at end\n\t4. Delete at begining\n\t5. Delete at end\n\t6. Delete nth node\n\t7. Display\n\t8. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                printf("\nEnter value to be inserted: ");
                int v1;
                scanf("%d",&v1);
                InsertAtBegin(v1);
                break;
            case 2:
                printf("\nEnter position to insert value: ");
                int v2 , pos1;
                scanf("%d",&pos1);
                printf("Enter value to be inserted: ");
                scanf("%d",&v2);
                InsertAtnthNode(pos1 , v2);
                break;
            case 3:
                printf("\nEnter value to insert at end: ");
                int v3;
                scanf("%d",&v3);
                InsertAtEnd(v3);
                break;
            case 4:
                DeleteAtBegin();
                break;
            case 5:
                DeleteAtEnd();
                break;
            case 6:
                printf("\nEnter position to delete element: ");
                int pos2;
                scanf("%d",&pos2);
                DeletenthNode(pos2);
                break;
            case 7:
                Display();
                break;
            case 8:
                printf("\n\t**THANK YOU!**\n");
                exit(0);
            default: 
                printf("\n\t**Chose a valid option**\n"); 
        }       
    }
    return 0;
}

// Test Cases

void testInsertAtBegin() {
    head = NULL;
    InsertAtBegin(5);
    assert(head->data == 5);
    assert(head->next == NULL);

    InsertAtBegin(10);
    assert(head->data == 10);
    assert(head->next->data == 5);
}

void testInsertAtnthNode() {
    head = NULL;
    InsertAtBegin(5);
    InsertAtBegin(10);
    InsertAtBegin(15);
    InsertAtBegin(20);

    InsertAtnthNode(3, 25);
    assert(head->data == 20);
    assert(head->next->next->data == 25);
    assert(head->next->next->next->data == 15);
    assert(head->next->next->next->next->data == 10);
    assert(head->next->next->next->next->next->data == 5);
    assert(head->next->next->next->next->next->next == NULL);
}

void testInsertAtEnd() {
    head = NULL;
    InsertAtEnd(5);
    assert(head->data == 5);
    assert(head->next == NULL);

    InsertAtEnd(10);
    assert(head->data == 5);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
}

void testDeleteAtBegin() {
    head = NULL;
    InsertAtBegin(5);
    InsertAtBegin(10);
    InsertAtBegin(15);
    InsertAtBegin(20);

    DeleteAtBegin();
    assert(head->data == 15);
    assert(head->next->data == 10);
    assert(head->next->next->data == 5);
    assert(head->next->next->next == NULL);

    DeleteAtBegin();
    assert(head->data == 10);
    assert(head->next->data == 5);
    assert(head->next->next == NULL);
}

void testDeleteAtEnd() {
    head = NULL;
    InsertAtBegin(5);
    InsertAtBegin(10);
    InsertAtBegin(15);
    InsertAtBegin(20);

    DeleteAtEnd();
    assert(head->data == 20);
    assert(head->next->data == 15);
    assert(head->next->next->data == 10);
    assert(head->next->next->next == NULL);

    DeleteAtEnd();
    assert(head->data == 20);
    assert(head->next->data == 15);
    assert(head->next->next == NULL);
}

void testDeletenthNode() {
    head = NULL;
    InsertAtBegin(5);
    InsertAtBegin(10);
    InsertAtBegin(15);
    InsertAtBegin(20);

    DeletenthNode(2);
    assert(head->data == 20);
    assert(head->next->data == 10);
    assert(head->next->next->data == 5);
    assert(head->next->next->next == NULL);

    DeletenthNode(1);
    assert(head->data == 10);
    assert(head->next->data == 5);
    assert(head->next->next == NULL);
}

void testDisplay() {
    head = NULL;
    Display(); // No elements to display

    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);

    Display(); // 30 20 10
}

int main() {
    testInsertAtBegin();
    testInsertAtnthNode();
    testInsertAtEnd();
    testDeleteAtBegin();
    testDeleteAtEnd();
    testDeletenthNode();
    testDisplay();

    printf("All test cases pass\n");
    return 0;
}