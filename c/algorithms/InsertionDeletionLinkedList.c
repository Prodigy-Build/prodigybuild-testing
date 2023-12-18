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
    assert(new != NULL);
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
    assert(pos > 0);

    struct node* temp = head;
    if (pos==1) {
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
    assert(pos > 0);

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

void binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) % 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;

    if(element == mid)
    printf("%d", &mid);

    if(element != yarr[right])
    {
        for(i = 0; i < left; i++)
        {
            if(element == i)
            {
            printf("%d", i);
            }
        }
    }
}

void test_InsertAtBegin()
{
    head = NULL;
    InsertAtBegin(1);
    assert(head->data == 1);
    assert(head->next == NULL);

    InsertAtBegin(7);
    assert(head->data == 7);
    assert(head->next->data == 1);
    assert(head->next->next == NULL);
}

void test_InsertAtnthNode()
{
    head = NULL;
    InsertAtnthNode(1, 9);
    assert(head == NULL);

    InsertAtnthNode(2, 8);
    assert(head == NULL);

    InsertAtBegin(7);
    InsertAtnthNode(2, 4);
    assert(head->data == 7);
    assert(head->next->data == 4);
    assert(head->next->next == NULL);

    InsertAtnthNode(3, 1);
    assert(head->data == 7);
    assert(head->next->data == 4);
    assert(head->next->next->data == 1);
    assert(head->next->next->next == NULL);
}

void test_InsertAtEnd()
{
    head = NULL;
    InsertAtnthNode(9);
    assert(head == NULL);

    InsertAtEnd(5);
    assert(head->data == 5);
    assert(head->next == NULL);

    InsertAtEnd(2);
    assert(head->data == 5);
    assert(head->next->data == 2);
    assert(head->next->next == NULL);
}

void test_DeleteAtBegin()
{
    head = NULL;
    DeleteAtBegin();

    InsertAtEnd(5);
    DeleteAtBegin();
    assert(head == NULL);

    InsertAtEnd(2);
    InsertAtEnd(7);
    DeleteAtBegin();
    assert(head->data == 7);
    assert(head->next == NULL);
}

void test_DeleteAtEnd()
{
    head = NULL;
    DeleteAtEnd();

    InsertAtEnd(2);
    DeleteAtEnd();
    assert(head == NULL);

    InsertAtEnd(5);
    InsertAtEnd(8);
    DeleteAtEnd();
    assert(head->data == 5);
    assert(head->next == NULL);
}

void test_DeletenthNode()
{
    head = NULL;
    DeletenthNode(1);
    
    InsertAtEnd(5);
    DeletenthNode(1);
    assert(head == NULL);

    InsertAtEnd(2);
    InsertAtEnd(7);
    DeletenthNode(2);
    assert(head->data == 2);
    assert(head->next == NULL);

    head = NULL;
    InsertAtEnd(2);
    InsertAtEnd(7);
    DeletenthNode(1);
    assert(head->data == 7);
    assert(head->next == NULL);
}

int main() {
    head = NULL;
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    Display();

    binsearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5);
    return 0;
}