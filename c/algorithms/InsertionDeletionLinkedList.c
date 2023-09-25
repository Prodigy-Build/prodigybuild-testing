#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

// Structure used to create node again and again when required..
struct node *CreateNode() {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    return new;
}

void InsertAtBegin(int value) {
    struct node *NewNode = CreateNode();
    if (head == NULL) { /*Only works when list is empty*/
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
            temp = temp->next; /*Accessing (n-1)th node*/
        }
        NewNode->next = temp->next; /*Linking nth node to (n+1)th node*/
        temp->next = NewNode; /*Linking (n-1)th node to nth node*/
    }
}

void InsertAtEnd(int value) {
    if (head == NULL) { /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**Use Insert at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        struct node *NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = temp->next;
        temp->next = NewNode; /*Links new node n to (n-1)th node*/
    }
}

void DeleteAtBegin() {
    if (head == NULL) { /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**No element exists**\n");
    } else {
        head = head->next; /*2nd node is now declared as head*/
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) { /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**No element exists**\n");
    } else if (head->next == NULL) {
        printf("\n\t**Use Delete at begining**\n");
    } else {
        struct node *temp = head;
        while(temp->next->next!=NULL) { /*Accessing (n-1)th node*/
            temp = temp->next;
        }
        temp->next = NULL; /*(n-1)th node will now point to null instead of nth node*/
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
        struct node *temp2 = temp->next; /*Accessing nth node, which we want to delete*/
        temp->next = temp2->next; /*(n-1) node is pointing to (n+1) node now. Breaking the link between (n-1),n,(n+1) nodes.*/
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
    printf("\nRunning test for InsertAtBegin\n");
    InsertAtBegin(5);
    Display();
}

void testInsertAtnthNode() {
    printf("\nRunning test for InsertAtnthNode\n");
    InsertAtnthNode(2, 10);
    Display();
}

void testInsertAtEnd() {
    printf("\nRunning test for InsertAtEnd\n");
    InsertAtEnd(15);
    Display();
}

void testDeleteAtBegin() {
    printf("\nRunning test for DeleteAtBegin\n");
    DeleteAtBegin();
    Display();
}

void testDeleteAtEnd() {
    printf("\nRunning test for DeleteAtEnd\n");
    DeleteAtEnd();
    Display();
}

void testDeletenthNode() {
    printf("\nRunning test for DeletenthNode\n");
    DeletenthNode(2);
    Display();
}

void runTests() {
    testInsertAtBegin();
    testInsertAtnthNode();
    testInsertAtEnd();
    testDeleteAtBegin();
    testDeleteAtEnd();
    testDeletenthNode();
}

void main() {
    head = NULL;
    runTests();
}

