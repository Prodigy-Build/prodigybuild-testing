import unittest
from recursive_bubble_sort import bubble_sort

class TestBubbleSort(unittest.TestCase):
    def test_bubble_sort(self):
        self.assertEqual(bubble_sort([0, 5, 2, 3, 2], 5), [0, 2, 2, 3, 5])
        self.assertEqual(bubble_sort([], 0), [])
        self.assertEqual(bubble_sort([-2, -45, -5], 3), [-45, -5, -2])
        self.assertEqual(bubble_sort([-23, 0, 6, -4, 34], 5), [-23, -4, 0, 6, 34])
        self.assertEqual(bubble_sort(['z','a','y','b','x','c'], 6), ['a', 'b', 'c', 'x', 'y', 'z'])
        self.assertEqual(bubble_sort([1.1, 3.3, 5.5, 7.7, 2.2, 4.4, 6.6]), [1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7])

if __name__ == '__main__':
     unittest.main()