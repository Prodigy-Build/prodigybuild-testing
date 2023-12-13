#include <assert.h>

void testInsertAtBegin(){
    head = NULL;
    InsertAtBegin(5);
    assert(head->data == 5);
    InsertAtBegin(10);
    assert(head->data == 10);  
}

void testInsertAtnthNode(){
    head = NULL;
    InsertAtBegin(20);
    InsertAtnthNode(2, 40);
    assert(head->next->data == 40);      
}

void testInsertAtEnd(){
  head = NULL;
  InsertAtBegin(30);
  InsertAtEnd(50);
  assert(head->next->data == 50);  
}

void testDeleteAtBegin(){
  head = NULL;
  InsertAtBegin(15);
  DeleteAtBegin();
  assert(head == NULL);  
}

void testDeleteAtEnd(){
  head = NULL;
  InsertAtBegin(35);
  InsertAtEnd(25);
  DeleteAtEnd();
  assert(head->next == NULL);  
}

void testDeletenthNode(){
  head = NULL;
  InsertAtBegin(45);
  InsertAtnthNode(2, 55);
  DeletenthNode(2);
  assert(head->next == NULL);  
}

int main() {
  testInsertAtBegin();
  testInsertAtnthNode();
  testInsertAtEnd();
  testDeleteAtBegin();
  testDeleteAtEnd();
  testDeletenthNode();

  printf("All test cases pass");
  
  return 0;
}