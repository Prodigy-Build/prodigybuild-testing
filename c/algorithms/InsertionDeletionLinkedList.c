#include <ctest.h>
#include <linkedlist.h>

CTEST(insertion_tests, test1) {
    struct node *head = NULL;
    head = InsertAtBegin(head, 5);
    head = InsertAtBegin(head, 10);
    head = InsertAtBegin(head, 15);
    head = InsertAtEnd(head, 20);
    head = InsertAtnthNode(head, 2, 25);
    ASSERT_EQUAL(25, head->next->next->data);
}

CTEST(deletion_tests, test1) {
    struct node *head = NULL;
    head = InsertAtBegin(head, 5);
    head = InsertAtBegin(head, 10);
    head = InsertAtBegin(head, 15);
    head = InsertAtEnd(head, 20);
    head = InsertAtnthNode(head, 2, 25);

    head = DeleteAtBegin(head);
    ASSERT_EQUAL(10, head->data);

    head = DeleteAtEnd(head);
    ASSERT_EQUAL(15, head->next->next->data);

    head = DeletenthNode(head, 2);
    ASSERT_EQUAL(20, head->next->data);
}