import unittest

class TestHeapSort(unittest.TestCase):
    
    def test_heap_sort(self):
        self.assertEqual(heap_sort([0, 5, 3, 2, 2]), [0, 2, 2, 3, 5])
        self.assertEqual(heap_sort([]), [])
        self.assertEqual(heap_sort([-2, -5, -45]), [-45, -5, -2])
        self.assertEqual(heap_sort([8, 1, 7, 6, 0]), [0, 1, 6, 7, 8])
        self.assertEqual(heap_sort([1]), [1])


if __name__ == "__main__":
    unittest.main()