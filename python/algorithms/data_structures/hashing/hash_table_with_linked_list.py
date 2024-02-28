import unittest

class TestHashTableWithLinkedList(unittest.TestCase):
    def setUp(self):
        self.hash_table = HashTableWithLinkedList()

    def test_set_value(self):
        self.hash_table._set_value('test', 'data')
        self.assertEqual(self.hash_table.values['test'][0], 'data')

    def test_collision_resolution(self):
        for i in range(self.hash_table.charge_factor):
            self.hash_table._set_value('test', 'data')
        self.assertEqual(self.hash_table._collision_resolution('test', 'data2'), 'test')

    def test_balanced_factor(self):
        for i in range(self.hash_table.charge_factor):
            self.hash_table._set_value(str(i), 'data')
        self.assertEqual(self.hash_table.balanced_factor(), 0)

if __name__ == '__main__':
    unittest.main()