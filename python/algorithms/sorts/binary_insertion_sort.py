import unittest
import random
import string

class TestBinaryInsertionSort(unittest.TestCase):
    def setUp(self):
        self.binary_insertion_sort = binary_insertion_sort  # the function to test
    
    def test_random(self):
        collection = [random.choice(range(-50, 50)) for _ in range(100)]
        self.assertEqual(self.binary_insertion_sort(collection), sorted(collection))

    def test_stable(self):
        original = ['d', 'a', 'b', 'e', 'c']
        expected = ['a', 'b', 'c', 'd', 'e']
        self.assertEqual(self.binary_insertion_sort(original), expected)

    def test_empty(self):
        collection = []
        self.assertEqual(self.binary_insertion_sort(collection), sorted(collection))

    def test_negative(self):
        collection = [-1, -2, -3]
        self.assertEqual(self.binary_insertion_sort(collection), sorted(collection))

    def test_string(self):
        collection = random.choices(string.ascii_letters + string.digits, k=100)
        self.assertEqual(self.binary_insertion_sort(collection), sorted(collection))


if __name__ == '__main__':
    unittest.main()