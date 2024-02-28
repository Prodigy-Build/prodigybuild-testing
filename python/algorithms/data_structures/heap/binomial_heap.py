```python
import unittest
from algorithms.data_structures.heap.binomial_heap import BinomialHeap

class BinomialHeapTestCase(unittest.TestCase):
    def test_insert(self):
        heap = BinomialHeap()
        heap.insert(5)
        heap.insert(3)
        heap.insert(7)
        heap.insert(1)
        heap.insert(9)
        self.assertEqual(heap.size, 5)
        self.assertEqual(heap.peek(), 1)

    def test_delete_min(self):
        heap = BinomialHeap()
        heap.insert(5)
        heap.insert(3)
        heap.insert(7)
        heap.insert(1)
        heap.insert(9)
        self.assertEqual(heap.delete_min(), 1)
        self.assertEqual(heap.size, 4)
        self.assertEqual(heap.peek(), 3)

    def test_merge_heaps(self):
        heap1 = BinomialHeap()
        heap1.insert(5)
        heap1.insert(3)
        heap1.insert(7)
        heap2 = BinomialHeap()
        heap2.insert(1)
        heap2.insert(9)
        merged_heap = heap1.merge_heaps(heap2)
        self.assertEqual(merged_heap.size, 5)
        self.assertEqual(merged_heap.peek(), 1)

    def test_pre_order(self):
        heap = BinomialHeap()
        heap.insert(5)
        heap.insert(3)
        heap.insert(7)
        heap.insert(1)
        heap.insert(9)
        pre_order = heap.pre_order()
        self.assertEqual(pre_order, [(1, 0), (3, 1), (9, 2), ('#', 3), ('#', 3), (7, 1), ('#', 3), ('#', 3)])

    def test_str(self):
        heap = BinomialHeap()
        heap.insert(5)
        heap.insert(3)
        heap.insert(7)
        heap.insert(1)
        heap.insert(9)
        heap_str = str(heap)
        expected_str = "1\n-#\n-3\n--#\n--#\n-9\n--#\n--#\n-7\n--#\n--#"
        self.assertEqual(heap_str, expected_str)

if __name__ == '__main__':
    unittest.main()
```