from collections import deque
from .hash_table import HashTable

class HashTableWithLinkedList(HashTable):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def _set_value(self, key, data):
        self.values[key] = deque([]) if self.values[key] is None else self.values[key]
        self.values[key].appendleft(data)
        self._keys[key] = self.values[key]

    def balanced_factor(self):
        return (
            sum(self.charge_factor - len(slot) for slot in self.values)
            / self.size_table
            * self.charge_factor
        )

    def _collision_resolution(self, key, data=None):
        if not (
            len(self.values[key]) == self.charge_factor and self.values.count(None) == 0
        ):
            return key
        return super()._collision_resolution(key, data)

# Unit Test Cases
def test_HashTableWithLinkedList():
    # Create a hash table with linked list
    hash_table = HashTableWithLinkedList(size_table=5, charge_factor=0.75)

    # Test _set_value method
    hash_table._set_value(0, 'A')
    assert hash_table.values[0] == deque(['A'])
    assert hash_table._keys[0] == deque(['A'])

    hash_table._set_value(1, 'B')
    assert hash_table.values[1] == deque(['B'])
    assert hash_table._keys[1] == deque(['B'])

    hash_table._set_value(0, 'C')
    assert hash_table.values[0] == deque(['C', 'A'])
    assert hash_table._keys[0] == deque(['C', 'A'])

    # Test balanced_factor method
    assert hash_table.balanced_factor() == 0.6

    # Test _collision_resolution method
    assert hash_table._collision_resolution(0) == 0
    assert hash_table._collision_resolution(1) == 1

test_HashTableWithLinkedList()