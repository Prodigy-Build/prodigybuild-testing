import unittest

class TestInsertionSort(unittest.TestCase):
    
    def test_insertion_sort(self):
        self.assertEqual(insertion_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertTrue(insertion_sort([]) == sorted([]))
        self.assertTrue(insertion_sort([-2, -5, -45]) == sorted([-2, -5, -45]))
        self.assertTrue(insertion_sort(['d', 'a', 'b', 'e', 'c']) == sorted(['d', 'a', 'b', 'e', 'c']))
        
        import random
        collection = random.sample(range(-50, 50), 100)
        self.assertTrue(insertion_sort(collection) == sorted(collection))
        
        import string
        collection = random.choices(string.ascii_letters + string.digits, k=100)
        self.assertTrue(insertion_sort(collection) == sorted(collection))

if __name__ == "__main__":
    unittest.main()