// A menu-driven C program which let's the user Insert , Delete , Display elements in list at different positions and situations. 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

// Structure used to create node again and again when required..
struct node *CreateNode(int value) {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    return new;
}

void InsertAtBegin(int value) {
    struct node *NewNode = CreateNode(value);
    NewNode->next = head;
    head = NewNode;
}

void InsertAtEnd(int value) {
    struct node *NewNode = CreateNode(value);
    if (head == NULL) {
        head = NewNode;
        return;
    }
    struct node *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = NewNode;
}

void InsertAtnthNode(int pos , int value) {
    struct node *NewNode = CreateNode(value);
    if(pos==1) {
        InsertAtBegin(value);
    } else {
        struct node* temp = head;
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}

void DeleteAtBegin() {
    if (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void DeleteAtEnd() {
    if (head != NULL) {
        if (head->next == NULL) {
            DeleteAtBegin();
        } else {
            struct node *temp = head;
            while(temp->next->next!=NULL) {
                temp = temp->next;
            }
            struct node *lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}

void DeletenthNode(int pos) {
    if (pos == 1) {
        DeleteAtBegin();
    } else {
        struct node *temp = head;
        for (int i=0; i<pos-2; i++) {
            temp = temp->next;
        }
        struct node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
    }
}

void Display() {
    struct node *temp = head;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
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
                putchar('\n');
                exit(0);
            default: 
                printf("\n\t**Chose a valid option**\n"); 
        }       
    }
}