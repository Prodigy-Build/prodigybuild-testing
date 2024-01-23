// A menu-driven C program which let's the user Insert , Delete , Display elements in list at different positions and situations. 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

Node *CreateNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtStart(int value) {
    Node *newNode = CreateNode(value);
    if (head)
        newNode->next = head;
    head = newNode;
}

void InsertAtEnd(int value) {
    Node *newNode = CreateNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node *temp = head;
    for (; temp->next; temp = temp->next);
    temp->next = newNode;
}

void InsertAtIndex(int index, int value) {
    if (index < 0)
        return;
    if (index == 0) {
        InsertAtStart(value);
        return;
    }
    Node *newNode = CreateNode(value);
    Node *temp = head;
    for (int i = 1; i < index && temp; i++)
        temp = temp->next;
    if (!temp)
        return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeleteAtStart() {
    if (!head)
        return;
    Node *temp = head;
    head = head->next;
    free(temp);
}

void DeleteAtEnd() {
    if (!head)
        return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    for (; temp->next->next; temp = temp->next);
    Node *end = temp->next;
    temp->next = NULL;
    free(end);
}

void DeleteAtIndex(int index) {
    if (index < 0 || !head)
        return;
    if (index == 0) {
        DeleteAtStart();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < index && temp->next; i++)
        temp = temp->next;
    if (!temp->next)
        return;
    Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void PrintList() {
    if (!head)
        printf("List is empty.\n");
    else {
        printf("List: ");
        for (Node *temp = head; temp; temp = temp->next)
            printf("%d -> ", temp->data);
        printf("NULL\n");
    }
} 

int main(void) {
    int value, index, choice;
    printf("Menu:\n1. Insert at start\n2. Insert at index\n3. Insert at end\n4. Delete at start\n5. Delete at index\n6. Delete at end\n7. Print List\n8. Clear console\n9. Exit\n");
    for (;;) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 9)
            break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                InsertAtStart(value);
                break;
            case 2:
                printf("Enter index and value: ");
                scanf("%d%d", &index, &value);
                InsertAtIndex(index, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                InsertAtEnd(value);
                break;
            case 4:
                DeleteAtStart();
                break;
            case 5:
                printf("Enter index: ");
                scanf("%d", &index);
                DeleteAtIndex(index);
                break;
            case 6:
                DeleteAtEnd();
                break;
            case 7:
                PrintList();
                break;
            case 8:
                system("clear");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}