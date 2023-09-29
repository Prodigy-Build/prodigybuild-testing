#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void Insert(int val) { 
    struct Node *NewNode = CreateNode(); 
    NewNode->value = val;
    NewNode->next = head;
    NewNode->prev = NULL;
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n"); 
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) { 
        temp = temp->next;
    }
    printf("\nBackward:\n"); 
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void testInsert() {
  struct Node* four = NULL;
  struct Node* three = NULL;
  struct Node* two = NULL;
  struct Node* one = NULL;
  
  Insert(1);
  one = head;
  assert(one->value == 1);
  assert(one->prev == NULL);
  assert(one->next == NULL);

  Insert(2);
  two = head;
  one = head->next;
  assert(two->value == 2);
  assert(two->prev == NULL);
  assert(two->next == one);
  assert(one->value == 1);
  assert(one->prev == two);
  assert(one->next == NULL);

  Insert(3);
  three = head;
  two = head->next;
  one = head->next->next;
  assert(three->value == 3);
  assert(three->prev == NULL);
  assert(three->next == two);
  assert(two->value == 2);
  assert(two->prev == three);
  assert(two->next == one);
  assert(one->value == 1);
  assert(one->prev == two);
  assert(one->next == NULL);

  Insert(4);
  four = head;
  three = head->next;
  two = head->next->next;
  one = head->next->next->next;
  assert(four->value == 4);
  assert(four->prev == NULL);
  assert(four->next == three);
  assert(three->value == 3);
  assert(three->prev == four);
  assert(three->next == two);
  assert(two->value == 2);
  assert(two->prev == three);
  assert(two->next == one);
  assert(one->value == 1);
  assert(one->prev == two);
  assert(one->next == NULL);
}

void testDisplay() {
  struct Node* temp = NULL;
  
  printf("\nForward:\n");
  temp = head;
  while(temp!=NULL) {
    printf("%d ",temp->value);
     temp = temp->next;
  }
}

void testReverseDisplay() {
  struct Node *temp = head;
  while(temp->next!=NULL) { 
    temp = temp->next;
  }
  printf("\nBackward:\n"); 
  while(temp!=NULL) {
    printf("%d ",temp->value);
    temp = temp->prev;
  }
  printf("\n");
}

int main() {
  testInsert();
  testDisplay();
  testReverseDisplay();
  
  return 0;
}