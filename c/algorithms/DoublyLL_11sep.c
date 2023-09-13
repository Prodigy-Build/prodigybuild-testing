#include <assert.h>
#include <stdio.h>

void testInsertAndDisplay() {
    Insert(5);
    Insert(10);
    Insert(15);
    struct Node* temp = head;
    assert(temp->value == 15);
    temp = temp->next;
    assert(temp->value == 10);
    temp = temp->next;
    assert(temp->value == 5);
}

void testReverseDisplay() {
    Insert(20);
    struct Node* temp = head;

    while (temp->next !=NULL){
        temp = temp->next;
    }

    assert(temp->value == 5);
    temp = temp->prev;
    assert(temp->value == 10);
    temp = temp->prev;
    assert(temp->value == 15);
    temp = temp->prev;
    assert(temp->value == 20);
}

int main() {
    testInsertAndDisplay();
    Display();
    testReverseDisplay();
    ReverseDisplay();

    return 0;
}