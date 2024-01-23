// A menu-driven C program which let's the user Insert , Delete , Display elements in list at different positions and situations. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Structure used to create node again and again when required..
Node *CreateNode() {
    Node *newNode = (Node*) malloc(sizeof(Node));
    return newNode;
}

void InsertAtBegin(int value) {
    Node *newNode = CreateNode();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void InsertAtnthNode(int pos , int value) {
    Node *newNode = CreateNode();
    newNode->data = value;

    if(pos==1) {
        newNode->next = head;
        head = newNode;
    } else { 
        Node *temp = head;
        for (int i=0; i<pos-2; i++) {
            temp = temp->next; /*Accessing (n-1)th node*/
        }
        newNode->next = temp->next; /*Linking nth node to (n+1)th node*/
        temp->next = newNode; /*Linking (n-1)th node to nth node*/
    }
}

void InsertAtEnd(int value) {
    Node *newNode = CreateNode();
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode; /*Links new node n to (n-1)th node*/
    }
}

void DeleteAtBegin() {
    if (head != NULL) { 
        Node *temp = head;
        head = head->next; /*2nd node is now declared as head*/
        free(temp);
    }
}

void DeleteAtEnd() {
    if (head != NULL) { 
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            Node *temp = head;
            while(temp->next->next!=NULL) { /*Accessing (n-1)th node*/
                temp = temp->next;
            }
            Node *t = temp->next;
            temp->next = NULL; /*(n-1)th node will now point to null instead of nth node*/
            free(t);
        }
    }
}

void DeletenthNode(int pos) {
    if (head != NULL) { 
        Node *temp = head;

        if (pos == 1) {
            head = temp->next; /*Now head will point to the 2nd node*/
            free(temp);
        } else {
            for (int i=0; i<pos-2; i++) {
                temp = temp->next;  /*Accessing (n-1)th node*/
            }
            Node *t = temp->next; /*Accessing nth node, which we want to delete*/
            temp->next = t->next; /*(n-1) node now points to (n+1) node. Breaking the link between (n-1),n,(n+1) nodes.*/
            free(t);
        }
    }
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    } else {
        Node *temp = head;
        printf("\nCurrent List:\n");
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main() {
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
}