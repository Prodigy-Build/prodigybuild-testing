// A menu-driven C program which let's the user Insert , Delete , Display elements in list at different positions and situations. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Function to create node again and again when required
Node *CreateNode() 
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    return newNode;
}

// Function to insert at the beginning of the list
void InsertAtBegin(int value) 
{
    Node *newNode = CreateNode();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert at nth node of the list
void InsertAtNthNode(int pos , int value) 
{
    Node* temp = head;
    if(pos <= 0) 
    {
        printf("\n\t**Invalid position**\n");
        return;
    }
    if(pos==1) 
    {
        InsertAtBegin(value);
    } 
    else 
    { 
        Node *newNode = CreateNode();
        newNode->data = value;
        for (int i=0; i<pos-2; i++) 
        {
            if(temp == NULL) 
            {
                printf("\n\t** position is beyond the length of the list**\n");
                return;
            }
            temp = temp->next; /*Accessing (n-1)th node*/
        }
        newNode->next = temp->next; /*Linking nth node to (n+1)th node*/
        temp->next = newNode; /*Linking (n-1)th node to nth node*/
    }
}

// Function to insert at the end of the list
void InsertAtEnd(int value) 
{
    Node *newNode = CreateNode();
    newNode->data = value;
    newNode->next = NULL;
   
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL) 
            temp = temp->next;
            
        temp->next = newNode;
    }
}

// Function to delete from the beginning of the list
void DeleteAtBegin() 
{
    if (head != NULL) 
    { /*Does not work when list is empty. Underflow situation...*/
        Node *temp = head;
        head = head->next; 
        free(temp);
        printf("\n\t**Element deleted successfully**\n");
    } 
    else
    {
        printf("\n\t**No element exists**\n");
    }
}

// Function to delete from the end of the list
void DeleteAtEnd() 
{
    Node *temp = head;
    
    if (head == NULL)
    {
        printf("\n\t**No element exists**\n");
    } 
    else if (head->next == NULL) 
    {
        DeleteAtBegin();
    } 
    else 
    {
        Node *prev = NULL;
        while(temp->next!=NULL) 
        { /*Accessing (n-1)th node*/
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("\n\t**Element deleted successfully**\n");
    }
}

// Function to delete the nth node from the list
void DeleteNthNode(int pos) 
{
    Node *temp = head;
    if (pos <= 0) 
    {
        printf("\n\t**Invalid position**\n");
        return;
    }
    if (pos == 1)
    {
        DeleteAtBegin();
    } 
    else 
    {
        for (int i=0; i<pos-2; i++)
        {
            if(temp == NULL) 
            {
                printf("\n\t** position is beyond the length of the list**\n");
                return;
            }
            temp = temp->next;
        }
        Node *node_to_delete = temp->next;
        if(node_to_delete == NULL)
        {
            printf("\n\t** position is beyond the length of the list**\n");
                return;
        }
        temp->next = node_to_delete->next;
        free(node_to_delete);
        printf("\n\t**Element deleted successfully**\n");
    }
}

// Function to display elements in the list 
void Display() 
{
    if (head == NULL)
    {
        printf("\n\t**No elements to display**\n\n");
    }
    else 
    {
        Node *temp = head;
        printf("\nCurrent List:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

// Main function
int main() 
{
    int ch;
    while (1) 
    {
        printf("\n\t\t**MENU**\n\t1. Insert at beginning\n\t2. Insert at nth position\n\t3. Insert at end\n\t4. Delete at beginning\n\t5. Delete at end\n\t6. Delete nth node\n\t7. Display\n\t8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
            {
                printf("\nEnter value to be inserted: ");
                int v1;
                scanf("%d",&v1);
                InsertAtBegin(v1);
                break;
            }
            case 2:
            {
                printf("\nEnter position to insert value: ");
                int v2 , pos1;
                scanf("%d",&pos1);
                printf("Enter value to be inserted: ");
                scanf("%d",&v2);
                InsertAtNthNode(pos1 , v2);
                break;
            }
            case 3:
            {
                printf("\nEnter value to insert at end: ");
                int v3;
                scanf("%d",&v3);
                InsertAtEnd(v3);
                break;
            }
            case 4:
            {
                DeleteAtBegin();
                break;
            }
            case 5:
            {
                DeleteAtEnd();
                break;
            }
            case 6:
            {
                printf("\nEnter position to delete element: ");
                int pos2;
                scanf("%d",&pos2);
                DeleteNthNode(pos2);
                break;
            }
            case 7:
            {
                Display();
                break;
            }
            case 8:
            {
                printf("\n\t**THANK YOU!**\n");
                return 0;
            }
            default: 
            {
                printf("\n\t**Choose a valid option**\n"); 
            }
        }       
    }
    return 0;
}