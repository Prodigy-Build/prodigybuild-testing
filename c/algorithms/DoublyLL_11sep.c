// Existing code goes here, omitted for brevity.

void Test() {
    // Test cases go here.
    printf("Running unit tests...\n");

    // Test case: Insert and verify.
    int testValue = 5;
    Insert(testValue);
    assert(head != NULL);
    assert(head->value == testValue);

    // Test case: Verify proper linking.
    int testNextValue = 10;
    Insert(testNextValue);
    assert(head != NULL);
    assert(head->value == testNextValue);
    assert(head->next != NULL);
    assert(head->next->value == testValue);

    // Test case: Display (manual inspection required).
    Display();

    // Test case: ReverseDisplay (manual inspection required).
    ReverseDisplay();
}

// main would now call Test.

void main() {
    // Original contents of main go here, omitted for brevity.
   
    Test();

    // Other code, if any, follows.
}