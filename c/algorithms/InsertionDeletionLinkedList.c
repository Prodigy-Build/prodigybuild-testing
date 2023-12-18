// Unit test cases for InsertAtBegin()
void test_InsertAtBegin()
{
    // Test case 1: Inserting 10 at the beginning
    head = NULL;
    InsertAtBegin(10);
    assert(head->data == 10);
    assert(head->next == NULL);

    // Test case 2: Inserting 20 at the beginning when there is already an element
    InsertAtBegin(20);
    assert(head->data == 20);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
}

// Unit test cases for InsertAtnthNode()
void test_InsertAtnthNode()
{
    // Test case 1: Inserting 30 at position 2 when there is only one element
    head = NULL;
    InsertAtBegin(10);
    InsertAtnthNode(2, 30);
    assert(head->data == 10);
    assert(head->next->data == 30);
    assert(head->next->next == NULL);

    // Test case 2: Inserting 40 at position 3 when there are already two elements
    InsertAtBegin(20);
    InsertAtnthNode(3, 40);
    assert(head->data == 20);
    assert(head->next->data == 30);
    assert(head->next->next->data == 40);
    assert(head->next->next->next == NULL);
}

// Unit test cases for InsertAtEnd()
void test_InsertAtEnd()
{
    // Test case 1: Inserting 50 at the end when the list is empty
    head = NULL;
    InsertAtEnd(50);
    assert(head->data == 50);
    assert(head->next == NULL);

    // Test case 2: Inserting 60 at the end when there are already elements
    InsertAtnthNode(2, 70);
    InsertAtnthNode(3, 80);
    InsertAtEnd(60);
    assert(head->data == 50);
    assert(head->next->data == 70);
    assert(head->next->next->data == 80);
    assert(head->next->next->next->data == 60);
    assert(head->next->next->next->next == NULL);
}

// Unit test cases for DeleteAtBegin()
void test_DeleteAtBegin()
{
    // Test case 1: Deleting the first element from a list of size 1
    head = NULL;
    InsertAtBegin(10);
    DeleteAtBegin();
    assert(head == NULL);

    // Test case 2: Deleting the first element from a list of size > 1
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeleteAtBegin();
    assert(head->data == 20);
    assert(head->next == NULL);
}

// Unit test cases for DeleteAtEnd()
void test_DeleteAtEnd()
{
    // Test case 1: Deleting the last element from a list of size 1
    head = NULL;
    InsertAtBegin(10);
    DeleteAtEnd();
    assert(head == NULL);

    // Test case 2: Deleting the last element from a list of size > 1
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeleteAtEnd();
    assert(head->data == 30);
    assert(head->next == NULL);
}

// Unit test cases for DeletenthNode()
void test_DeletenthNode()
{
    // Test case 1: Deleting the element at position 1 when there is only one element
    head = NULL;
    InsertAtBegin(10);
    DeletenthNode(1);
    assert(head == NULL);

    // Test case 2: Deleting the element at position 2 when there are already elements
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeletenthNode(2);
    assert(head->data == 30);
    assert(head->next == NULL);
}

// Unit test cases for Display()
void test_Display()
{
    // Test case 1: Displaying an empty list
    head = NULL;
    Display(); // No output expected

    // Test case 2: Displaying a list with elements
    InsertAtBegin(10);
    InsertAtnthNode(2, 20);
    InsertAtEnd(30);
    Display(); // Expected output: "Current List:\n10 20 30 "
}

// Unit test case for the main program
void test_main()
{
    // No meaningful test can be written for the main program as it depends on user input
    // and involves interactions with the console. Hence, it is not testable.
}

int main()
{
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    test_Display();
    test_main();

    return 0;
}