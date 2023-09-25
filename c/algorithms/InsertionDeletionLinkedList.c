#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

struct node *head;

int init_suite(void) {
    head = NULL;
    return 0;
}

int clean_suite(void) {
    return 0;
}

void test_insert_at_begin(void) {
    InsertAtBegin(5);
    CU_ASSERT_PTR_NOT_NULL(head);
    CU_ASSERT_EQUAL(head->data, 5);
}

void test_insert_at_position(void) {
    InsertAtnthNode(2, 10);
    CU_ASSERT_EQUAL(head->next->data, 10);
}

void test_insert_at_end(void) {
    InsertAtEnd(15);
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    CU_ASSERT_EQUAL(temp->data, 15);
}

void test_delete_at_begin(void) {
    DeleteAtBegin();
    CU_ASSERT_PTR_NOT_EQUAL(head, NULL);
    CU_ASSERT_NOT_EQUAL(head->data, 5);
}

void test_delete_at_end(void) {
    DeleteAtEnd();
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    CU_ASSERT_NOT_EQUAL(temp->data, 15);
}

void test_delete_n_node(void) {
    DeletenthNode(2);
    CU_ASSERT_PTR_NOT_EQUAL(head->next, NULL);
    CU_ASSERT_NOT_EQUAL(head->next->data, 10);
}

int main() {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("test_suite", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (
        (NULL == CU_add_test(pSuite, "test_insert_at_begin", test_insert_at_begin)) ||
        (NULL == CU_add_test(pSuite, "test_insert_at_position", test_insert_at_position)) ||
        (NULL == CU_add_test(pSuite, "test_insert_at_end", test_insert_at_end)) ||
        (NULL == CU_add_test(pSuite, "test_delete_at_begin", test_delete_at_begin)) ||
        (NULL == CU_add_test(pSuite, "test_delete_at_end", test_delete_at_end)) ||
        (NULL == CU_add_test(pSuite, "test_delete_n_node", test_delete_n_node))
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}