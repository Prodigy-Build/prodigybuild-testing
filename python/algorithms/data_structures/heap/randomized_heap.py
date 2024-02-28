```python
import unittest
from algorithms.data_structures.heap.randomized_heap import RandomizedHeap

class RandomizedHeapTestCase(unittest.TestCase):
    def test_insert(self):
        rh = RandomizedHeap()
        rh.insert(3)
        rh.insert(1)
        rh.insert(3)
        rh.insert(7)
        self.assertEqual(rh.to_sorted_list(), [1, 3, 3, 7])

    def test_pop(self):
        rh = RandomizedHeap([3, 1, 3, 7])
        self.assertEqual(rh.pop(), 1)
        self.assertEqual(rh.pop(), 3)
        self.assertEqual(rh.pop(), 3)
        self.assertEqual(rh.pop(), 7)
        with self.assertRaises(IndexError):
            rh.pop()

    def test_top(self):
        rh = RandomizedHeap()
        rh.insert(3)
        self.assertEqual(rh.top(), 3)
        rh.insert(1)
        self.assertEqual(rh.top(), 1)
        rh.insert(3)
        self.assertEqual(rh.top(), 1)
        rh.insert(7)
        self.assertEqual(rh.top(), 1)
        with self.assertRaises(IndexError):
            rh.clear()

    def test_clear(self):
        rh = RandomizedHeap([3, 1, 3, 7])
        rh.clear()
        with self.assertRaises(IndexError):
            rh.pop()

    def test_to_sorted_list(self):
        rh = RandomizedHeap([3, 1, 3, 7])
        self.assertEqual(rh.to_sorted_list(), [1, 3, 3, 7])

    def test_bool(self):
        rh = RandomizedHeap()
        self.assertFalse(bool(rh))
        rh.insert(1)
        self.assertTrue(bool(rh))
        rh.clear()
        self.assertFalse(bool(rh))

if __name__ == '__main__':
    unittest.main()
```