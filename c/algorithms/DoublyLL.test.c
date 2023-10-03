#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testInsert() {
    struct Node {
        int value;
        struct Node *next;
        struct Node *prev;
    };
    struct Node *head = NULL;

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

    /* Test cases */
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);

    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->next->value == 1);
    assert(head->next->next->next == NULL);
    assert(head->next->next->prev == head->next);

    Insert(4);
    assert(head->value == 4);
    assert(head->next->value == 3);
    assert(head->next->next->value == 2);
    assert(head->next->next->next->value == 1);
    assert(head->next->next->next->next == NULL);
    assert(head->next->next->next->prev == head->next->next);

    printf("Insert test cases pass\n");
}

int main() {
    testInsert();

    return 0;
}