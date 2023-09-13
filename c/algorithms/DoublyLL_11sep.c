//To write Unit test cases, we will use the assert function. The assert.h header file should be included.

#include <assert.h>

void test_insert() {
    head = NULL; //Resetting the head to NULL for each test case
    Insert(5);
    assert(head->value == 5);
    assert(head->next == NULL);
    assert(head->prev == NULL);
  
    Insert(10);
    assert(head->value == 10);
    assert(head->next->value == 5);
    assert(head->prev == NULL);
    assert(head->next->prev == head);  
}

void test_reverse_display() {
    head = NULL; //Resetting the head to NULL for each test case
    Insert(3);
    Insert(2);
    Insert(1);
    struct Node *temp = head;
    while(temp->next!=NULL) { 
        temp = temp->next;
    }
    assert(temp->value == 3);
    assert(temp->prev->value == 2);
    assert(temp->prev->prev->value == 1);

}

void test_cases() {
    test_insert();
    test_reverse_display();
}

void main() {
    test_cases();
    //Your original main function code here. 
}