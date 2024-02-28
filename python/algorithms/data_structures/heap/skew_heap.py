```python
import unittest
from algorithms.data_structures.heap.skew_heap import SkewHeap

class SkewHeapTestCase(unittest.TestCase):
    def test_insert(self):
        sh = SkewHeap()
        sh.insert(3)
        sh.insert(1)
        sh.insert(3)
        sh.insert(7)
        self.assertEqual(list(sh), [1, 3, 3, 7])

    def test_pop(self):
        sh = SkewHeap([3, 1, 3, 7])
        self.assertEqual(sh.pop(), 1)
        self.assertEqual(sh.pop(), 3)
        self.assertEqual(sh.pop(), 3)
        self.assertEqual(sh.pop(), 7)
        with self.assertRaises(IndexError):
            sh.pop()

    def test_top(self):
        sh = SkewHeap()
        sh.insert(3)
        self.assertEqual(sh.top(), 3)
        sh.insert(1)
        self.assertEqual(sh.top(), 1)
        sh.insert(3)
        self.assertEqual(sh.top(), 1)
        sh.insert(7)
        self.assertEqual(sh.top(), 1)
        sh.clear()
        with self.assertRaises(IndexError):
            sh.top()

    def test_clear(self):
        sh = SkewHeap([3, 1, 3, 7])
        sh.clear()
        with self.assertRaises(IndexError):
            sh.pop()

if __name__ == '__main__':
    unittest.main()
```
