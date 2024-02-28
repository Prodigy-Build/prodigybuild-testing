# New code with unit test cases

class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

    def __repr__(self):
        """Returns a visual representation of the node and all its following nodes."""
        string_rep = ""
        temp = self
        while temp:
            string_rep += f"<{temp.data}> ---> "
            temp = temp.next
        string_rep += "<END>"
        return string_rep


def make_linked_list(elements_list):
    """Creates a Linked List from the elements of the given sequence
    (list/tuple) and returns the head of the Linked List."""

    # if elements_list is empty
    if not elements_list:
        raise Exception("The Elements List is empty")

    # Set first element as Head
    head = Node(elements_list[0])
    current = head
    # Loop through elements from position 1
    for data in elements_list[1:]:
        current.next = Node(data)
        current = current.next
    return head


# Unit test cases
def test_make_linked_list():
    # Test case 1: Empty list
    elements_list = []
    try:
        make_linked_list(elements_list)
    except Exception as e:
        assert str(e) == "The Elements List is empty"

    # Test case 2: Single element list
    elements_list = [1]
    linked_list = make_linked_list(elements_list)
    assert linked_list.data == 1
    assert linked_list.next is None

    # Test case 3: Multiple element list
    elements_list = [1, 3, 5, 32, 44, 12, 43]
    linked_list = make_linked_list(elements_list)
    assert linked_list.data == 1
    assert linked_list.next.data == 3
    assert linked_list.next.next.data == 5
    assert linked_list.next.next.next.data == 32
    assert linked_list.next.next.next.next.data == 44
    assert linked_list.next.next.next.next.next.data == 12
    assert linked_list.next.next.next.next.next.next.data == 43
    assert linked_list.next.next.next.next.next.next.next is None

    print("All test cases pass")


if __name__ == "__main__":
    test_make_linked_list()